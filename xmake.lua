add_rules("mode.debug", "mode.release")

set_languages("c++17")
set_encodings("utf-8")

option("test")
option_end()

if has_config("test") then
    add_requires("doctest")
    -- -- Enable asan will make debug fail
    -- set_policy("build.sanitizer.address", true)
    -- if is_plat("windows") then
    --     add_defines("_DISABLE_VECTOR_ANNOTATION")
    --     add_defines("_DISABLE_STRING_ANNOTATION")
    -- end
end

target("smoothcpp")
    set_kind("$(kind)")
    add_files("scpp/**.cpp")
    add_includedirs(".", {public = true})
    add_headerfiles("(scpp/**.h)")
    add_options("test")
    
    if is_plat("windows") then
        add_defines("WIN32_LEAN_AND_MEAN", {public = true})
        add_defines("NOMINMAX", {public = true})
        if is_kind("shared") then
            add_rules("utils.symbols.export_all", {export_classes = true})
        end
    end

for _, file in ipairs(os.files("test/*.cpp")) do
    local name = path.basename(file)
    target(name)
        set_kind("binary")
        add_packages("doctest")
        set_default(false)
        add_files("test/" .. name .. ".cpp")
        add_tests("default")
        add_deps("smoothcpp")
end

