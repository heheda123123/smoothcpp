#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <scpp/option/option.h>

using namespace scpp;

TEST_CASE("testing Option get bool arg") {
	Option opt;
	opt.add("aa", true, opt.T_BOOL, true, "arg aa");
	const char *arg[4] = {"-aa", "world", "example", "hello"};
	opt.parse(5, arg);
	bool data_aa = opt.get("aa");
	CHECK(data_aa == true);
	bool has_aa = opt.has("aa");
	CHECK(has_aa == true);
}

TEST_CASE("testing Option get int arg") {
	Option opt;
	opt.add("aa", 123, opt.T_INT, true, "arg aa");
	const char *arg[5] = {"./a.out", "-aa", "123", "-cc", "hello"};
	opt.parse(5, arg);
	int data_aa = opt.get("aa");
	CHECK(data_aa == 123);
	bool has_aa = opt.has("aa");
	CHECK(has_aa == true);
}

TEST_CASE("testing Option get double arg") {
	Option opt;
	opt.add("aa", 123.0, opt.T_DOUBLE, true, "arg aa");
	const char *arg[5] = {"./a.out", "-aa", "123", "-cc", "hello"};
	opt.parse(5, arg);
	double data_aa = opt.get("aa");
	CHECK(data_aa == 123.0);
	bool has_aa = opt.has("aa");
	CHECK(has_aa == true);
}

TEST_CASE("testing Option get string arg") {
	Option opt;
	opt.add("aa", "123", opt.T_INT, true, "arg aa");
	const char *arg[5] = {"./a.out", "-aa", "222", "-cc", "hello"};
	opt.parse(5, arg);
	std::string data_aa = opt.get("aa");
	CHECK(data_aa == "123");
	bool has_aa = opt.has("aa");
	CHECK(has_aa == true);
}

TEST_CASE("testing Option much test once") {
	Option opt;
	opt.add("aa", 111, opt.T_INT, true, "arg aa");
	opt.add("bb", "123", opt.T_STRING, false, "arg aa");
	opt.add("cc", true, opt.T_BOOL, true, "arg aa");
	const char *arg[5] = {"./a.out","-aa", "123", "-cc", "hello"};
	opt.parse(5, arg);
	int data_aa = opt.get("aa");
	CHECK(data_aa == 123);
	bool has_bb = opt.has("bb");
	CHECK(has_bb == false);
	bool cc = opt.get("cc");
	CHECK(cc == true);
}