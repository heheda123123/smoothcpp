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
