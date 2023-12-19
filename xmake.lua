add_rules("mode.debug", "mode.release")

set_languages("c++17")

if is_mode("debug") then
    add_requires("doctest")
end

target("smoothcpp")
set_kind("$(kind)")
add_files("scpp/**.cpp")
add_includedirs(".", {public = true})
add_headerfiles("(scpp/**.h)")

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

