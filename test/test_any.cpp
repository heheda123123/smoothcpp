#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/any/any.h>

using namespace scpp;

TEST_CASE("testing Any null") {
    Any aa;
    bool bb = aa;
    int cc = aa;
    double dd = aa;
    std::string ee = aa;
    CHECK(bb == false);
    CHECK(cc == 0);
    CHECK(dd == 0);
    CHECK(ee == "");
}

TEST_CASE("testing Any bool") {
    Any aa = true;
    bool bb = aa;
    int cc = aa;
    double dd = aa;
    std::string ee = aa;
    CHECK(bb == true);
    CHECK(cc == 1);
    CHECK(dd == 1);
    CHECK(ee == "true");
}

TEST_CASE("testing Any int") {
    Any aa = 123;
    bool bb = aa;
    int cc = aa;
    double dd = aa;
    std::string ee = aa;
    CHECK(bb == true);
    CHECK(cc == 123);
    CHECK(dd == 123);
    CHECK(ee == "123");
}

TEST_CASE("testing Any double") {
    Any aa = 123.1;
    bool bb = aa;
    int cc = aa;
    double dd = aa;
    std::string ee = aa;
    CHECK(bb == true);
    CHECK(cc == 123);
    CHECK(dd == 123.1);
    CHECK(ee == "123.1");
}

TEST_CASE("testing Any string") {
    Any aa = "xxx";
    bool bb = aa;
    int cc = aa;
    double dd = aa;
    std::string ee = aa;
    CHECK(bb == true);
    CHECK(cc == 0);
    CHECK(dd == 0);
    CHECK(ee == "xxx");
}

TEST_CASE("testing Any int like string") {
    Any aa = "123";
    bool bb = aa;
    int cc = aa;
    double dd = aa;
    std::string ee = aa;
    CHECK(bb == true);
    CHECK(cc == 123);
    CHECK(dd == 123);
    CHECK(ee == "123");
}

TEST_CASE("testing Any double like string") {
    Any aa = "123.3";
    bool bb = aa;
    int cc = aa;
    double dd = aa;
    std::string ee = aa;
    CHECK(bb == true);
    CHECK(cc == 123);
    CHECK(dd == 123.3);
    CHECK(ee == "123.3");
}

TEST_CASE("testing Any compare") {
    Any zz;
    Any aa = "123.3";
    Any bb = true;
    Any cc = 12;
    Any dd = "11.11";
    Any ee = "zzz";
    Any ff = Any{};
    CHECK(zz != aa);
    CHECK(zz != bb);
    CHECK(zz != cc);
    CHECK(zz != dd);
    CHECK(zz != ee);
    CHECK(zz == Any{});
    CHECK(zz == ff);
}
