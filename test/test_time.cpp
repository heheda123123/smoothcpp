#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "scpp/time/time.h"
#include "scpp/string/string.h"

using namespace scpp;

TEST_CASE("testing Time constructor") {
    Time t1;
    CHECK(contains(t1.format("%Y-%m-%d %H:%M:%S"), "-") == true);
}

TEST_CASE("testing Time operator-") {
    Time t1;
    Time::sleep(500);
    Time t2;
    CHECK((t2 - t1 - 500) < 50);
}

TEST_CASE("testing Time reset") {
    Time t1;
    Time::sleep(500);
    Time t2;
    t1.reset();
    CHECK((t2 - t1) < 50);
}

TEST_CASE("testing Time elapse") {
    Time t1;
    CHECK(t1.elapse() < 100);
}

