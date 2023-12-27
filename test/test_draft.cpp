#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/option/option.h>

using namespace scpp;

TEST_CASE("testing Option add int") {
    Option opt;
    opt.add("name", Option::V_NUMBER, "arg name");
    const char *arg[5] = {"./a.out", "-name", "123", "example", "hello"};
    opt.parse(5, arg);
    int data_name = opt.get("name");
    CHECK(data_name == 123);
    bool has_name = opt.has("name");
    CHECK(has_name == true);
}