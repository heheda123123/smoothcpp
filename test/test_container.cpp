#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/container/container.h>
#include <vector>
#include <list>

using namespace scpp;

TEST_CASE("testing contains with vector") {
	std::vector<int> intVector = {1, 2, 3, 4, 5};
	CHECK(contains(intVector, 3) == true);
	CHECK(contains(intVector, 33) == false);
}

TEST_CASE("testing contains with list") {
	std::list<int> intVector = {1, 2, 3, 4, 5};
	CHECK(contains(intVector, 3) == true);
	CHECK(contains(intVector, 33) == false);
}

TEST_CASE("testing contains with list string") {
	std::list<std::string> intVector = {"aa", "bb", "cc"};
	CHECK(contains(intVector, "aa") == true);
	CHECK(contains(intVector, "33") == false);
}

