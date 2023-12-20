#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/option/option.h>

using namespace scpp;

TEST_CASE("testing Option add bool") {
    Option opt;
    opt.add("name", Option::V_BOOL, "arg name");
    const char *arg[5] = {"./a.out", "-name", "world", "example", "hello"};
    opt.parse(5, arg);
    bool data_name = opt.get("name");
    CHECK(data_name == true);
    bool has_name = opt.has("name");
    CHECK(has_name == true);
}

TEST_CASE("testing Option add string use default value") {
    Option opt;
    opt.add("name", Option::V_STRING, "arg name", "aaa");
    const char *arg[5] = {"./a.out", "-name", "world", "example", "hello"};
    opt.parse(5, arg);
    std::string data_name = opt.get("name");
    CHECK(data_name == "world");
    bool has_name = opt.has("name");
    CHECK(has_name == true);
}

TEST_CASE("testing Option add string use default value") {
    Option opt;
    opt.add("name", Option::V_STRING, "arg name", "xzz");

    const char *arg[5] = {"./a.out", "-aa", "world", "example", "hello"};
    opt.parse(5, arg);

    std::string data_name = opt.get("name");
    CHECK(data_name == "xzz");
    bool has_name = opt.has("name");
    CHECK(has_name == true);
}

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

TEST_CASE("testing Option add double") {
    Option opt;
    opt.add("name", Option::V_NUMBER, "arg name");
    const char *arg[5] = {"./a.out", "-name", "123.1", "example", "hello"};
    opt.parse(5, arg);
    double data_name = opt.get("name");
    CHECK(data_name == 123.1);
    bool has_name = opt.has("name");
    CHECK(has_name == true);
}

TEST_CASE("testing Option add string") {
    Option opt;
    opt.add("name", Option::V_STRING, "arg name");
    const char *arg[5] = {"./a.out", "-name", "world", "example", "hello"};
    opt.parse(5, arg);
    std::string data_name = opt.get("name");
    CHECK(data_name == "world");
    bool has_name = opt.has("name");
    CHECK(has_name == true);
}

TEST_CASE("testing Option add number no arg value") {
    Option opt;
    opt.add("name", Option::V_NUMBER, "arg name");
    const char *arg[2] = {"./a.out", "-name"};
    CHECK_THROWS_WITH(opt.parse(2, arg), "Not enough parameters provided");
}

TEST_CASE("testing Option default value mismatch type") {
    Option opt;
    CHECK_THROWS_WITH(opt.add("name", Option::V_NUMBER, "arg name", "heheda"), "default value type conflict");
}

TEST_CASE("testing Option default value mismatch type") {
    Option opt;
    CHECK_THROWS_WITH(opt.add_opt("name", Option::V_NUMBER, "arg name", "heheda"), "default value type conflict");
}

TEST_CASE("testing Option add_opt string") {
    Option opt;
    opt.add_opt("name", Option::V_STRING, "arg name");
    const char *arg[5] = {"./a.out", "-aa", "world", "example", "hello"};
    opt.parse(5, arg);

    std::string data_name = opt.get("name");
    CHECK(data_name == "");
    bool has_name = opt.has("name");
    CHECK(has_name == false);
}

TEST_CASE("testing Option add string no arg key") {
    Option opt;
    opt.add("name", Option::V_STRING, "arg name");
    const char *arg[5] = {"./a.out", "-aa", "world", "example", "hello"};
    CHECK_THROWS_WITH(opt.parse(5, arg), "required arg not provided");
}
