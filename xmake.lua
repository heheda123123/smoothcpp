add_rules("mode.debug", "mode.release")

set_languages("c++17")

-- option("test")
-- option_end()

-- if has_config("test") then
--     add_requires("doctest")
-- end

add_requires("doctest")
    
target("smoothcpp")
set_kind("$(kind)")
add_files("scpp/**.cpp")
add_includedirs(".", {public = true})
add_headerfiles("(scpp/**.h)")
if is_plat("windows") and is_kind("shared") then
    add_rules("utils.symbols.export_all", {export_classes = true})
end
add_options("test")


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



