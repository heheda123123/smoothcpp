#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/any/any.h>
#include "scpp/string/string.h"
#include <sstream>

using namespace scpp;

TEST_CASE("testing Any null") {
	Any a;
    std::stringstream ss;
    ss << a;
    CHECK(contains(ss.str(), "type: null") == true);
    int b;
    CHECK_THROWS_WITH(b = a, "not int type");
}

TEST_CASE("testing Any bool") {
	Any a = true;
    std::stringstream ss;
    ss << a;
    CHECK(contains(ss.str(), "type: bool") == true);
    int b;
    CHECK_THROWS_WITH(b = a, "not int type");
    bool c = a;
    CHECK(c == true);
}

TEST_CASE("testing Any int") {
	Any a = 123;
    std::stringstream ss;
    ss << a;
    CHECK(contains(ss.str(), "type: int") == true);
    bool b;
    CHECK_THROWS_WITH(b = a, "not bool type");
    int c = a;
    CHECK(c == 123);
}

TEST_CASE("testing Any double") {
	Any a = 123.1;
    std::stringstream ss;
    ss << a;
    CHECK(contains(ss.str(), "type: double") == true);
    bool b;
    CHECK_THROWS_WITH(b = a, "not bool type");
    double c = a;
    CHECK(c == 123.1);
}

TEST_CASE("testing Any string") {
	Any a = "123";
    std::stringstream ss;
    ss << a;
    CHECK(contains(ss.str(), "type: string") == true);
    bool b;
    CHECK_THROWS_WITH(b = a, "not bool type");
    std::string c = a;
    CHECK(c == "123");
}
