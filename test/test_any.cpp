#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/any/any.h>
#include <vector>

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

TEST_CASE("testing Any vector int") {
    std::vector<int> ttt = {1, 2, 3, 4, 5};
    Any aa = ttt;
    std::vector<int> zzz = aa;
    CHECK(zzz[0] == 1);
    CHECK(zzz[4] == 5);
}

TEST_CASE("testing Any vector string") {
    std::vector<std::string> ttt = {"aa", "oo", "pp"};
    Any aa = ttt;
    std::vector<std::string> zzz = aa;
    CHECK(zzz[0] == "aa");
    CHECK(zzz[2] == "pp");
}

TEST_CASE("testing Any vector bool") {
    std::vector<bool> ttt = {true, false, true};
    Any aa = ttt;
    std::vector<bool> zzz = aa;
    CHECK(zzz[0] == true);
    CHECK(zzz[2] == true);
}

TEST_CASE("testing Any map string int") {
    std::map<std::string, int> ttt = {{"111", 123}, {"222", 333}};
    Any aa = ttt;
    std::map<std::string, int> zzz = aa;
    CHECK(zzz["111"] == 123);
    CHECK(zzz["222"] == 333);
}

TEST_CASE("testing Any map string int") {
    std::map<std::string, std::string> ttt = {{"111", "123"}, {"222", "333"}};
    Any aa = ttt;
    std::map<std::string, std::string> zzz = aa;
    CHECK(zzz["111"] == "123");
    CHECK(zzz["222"] == "333");
}

