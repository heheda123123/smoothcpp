#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/any/any.h>

using namespace scpp;

TEST_CASE("testing Any null") {
    Any aa;
	CHECK(aa.type() == Any::Type::V_NULL);
}

TEST_CASE("testing Any bool") {
    Any aa = true;
    bool bb = aa;
    CHECK(bb == true);
}

TEST_CASE("testing Any int") {
    Any aa = 123;
    int cc = aa;
    CHECK(cc == 123);
}

TEST_CASE("testing Any double") {
    Any aa = 123.1;
    double dd = aa;
    CHECK(dd == 123.1);
}

TEST_CASE("testing Any string") {
    Any aa = "xxx";
    std::string ee = aa;
    CHECK(ee == "xxx");
}

