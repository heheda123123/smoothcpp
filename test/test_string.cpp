#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "scpp/string/string.h"
#include "doctest/doctest.h"

using namespace scpp;


TEST_CASE("testing to_lower") {
    CHECK(to_lower("aAaAAbb") == "aaaaabb");
    CHECK(to_lower("aAaAA  bb") == "aaaaa  bb");
}

TEST_CASE("testing to_lower with chinese") {
    CHECK(to_lower("aAaA呵呵哒Ab你好b") == "aaaa呵呵哒ab你好b");
    CHECK(to_lower("aAaAA  bb") == "aaaaa  bb");
}

TEST_CASE("testing to_upper") {
    CHECK(to_upper("aAaAAbb") == "AAAAABB");
    CHECK(to_upper("aAaAA  bb") == "AAAAA  BB");
}

TEST_CASE("testing to_upper with chinese") {
    CHECK(to_upper("aAaAAb狗哥b") == "AAAAAB狗哥B");
    CHECK(to_upper("aAaAA  bb") == "AAAAA  BB");
}

TEST_CASE("testing ltrim") {
    CHECK(ltrim("hello world", "eh") == "llo world");
    CHECK(ltrim(" hello world", "eh") == " hello world");
    CHECK(ltrim("   hello world") == "hello world");
    CHECK(ltrim("hello world   ") == "hello world   ");
}

TEST_CASE("testing rtrim") {
    CHECK(rtrim("hello world", "drl") == "hello wo");
    CHECK(rtrim("hello world ", "eh") == "hello world ");
    CHECK(rtrim(" hello world") == " hello world");
    CHECK(rtrim("hello world   ") == "hello world");
}

TEST_CASE("testing trim") {
    CHECK(trim("hello world", "drl") == "hello wo");
    CHECK(trim("hello world", "he") == "llo world");
    CHECK(trim("hello world", "ehd") == "llo worl");
    CHECK(trim("   hello world ") == "hello world");
    CHECK(trim("hello world   ") == "hello world");
    CHECK(trim("   hello world") == "hello world");
    CHECK(trim("   hello world", "   hello world") == "");
}

TEST_CASE("testing split_str") {
    CHECK(split_str("hello world", "lo") == std::vector<std::string>{"hel", " world"});
    CHECK(split_str("hello world ") == std::vector<std::string> {"hello", "world"});
}

TEST_CASE("testing split_str with chinese") {
    CHECK(split_str("hello world", "lo") == std::vector<std::string>{"hel", " world"});
    CHECK(split_str("hello world 呵呵哒") == std::vector<std::string> {"hello", "world", "呵呵哒"});
}

TEST_CASE("testing split_chars") {
    CHECK(split_chars("hello world", "lo") == std::vector<std::string> {"he", "", "", " w", "r", "d"});
    CHECK(split_chars("hello world ") == std::vector<std::string> {"hello", "world", ""});
}

TEST_CASE("testing join") {
    std::vector<std::string> va = {"aa", "bb", "cc"};
    CHECK(join(va, "lo") == "aalobblocc");
    CHECK(join(va, " ") == "aa bb cc");
    CHECK(join(va, "") == "aabbcc");
}

TEST_CASE("testing to_string vector") {
    std::vector<std::string> va = {"aa", "bb", "cc"};
    CHECK(to_string(va) == "[\"aa\", \"bb\", \"cc\"]");
}

TEST_CASE("testing to_string map") {
    std::map<std::string, int> ma = {{"aa", 1}, {"bb", 2}, {"cc", 3}};
    CHECK(to_string(ma) == R"({"aa": 1, "bb": 2, "cc": 3})");
}

TEST_CASE("testing to_string unordered_map") {
    std::unordered_map<std::string, int> ma = {{"aa", 1}, {"bb", 2}, {"cc", 3}};
    CHECK(to_string(ma) == R"({"aa": 1, "bb": 2, "cc": 3})");
}

TEST_CASE("testing to_string list") {
    std::set<std::string> va = {"aa", "bb", "cc"};
    CHECK(to_string(va) == "{\"aa\", \"bb\", \"cc\"}");
}

TEST_CASE("testing to_string set") {
    std::list<std::string> va = {"aa", "bb", "cc"};
    CHECK(to_string(va) == "[\"aa\", \"bb\", \"cc\"]");
}

TEST_CASE("testing has_prefix") {
    CHECK(has_prefix("aabbdd", "aa") == true);
    CHECK(has_prefix(" aabbdd", "aa") == false);
}

TEST_CASE("testing has_suffix") {
    CHECK(has_suffix("aabbddzz", "zz") == true);
    CHECK(has_suffix(" aabbdd ", "aa") == false);
}

TEST_CASE("testing contains") {
    CHECK(contains("aabbddzza", "zz") == true);
    CHECK(contains(" ababbdd ", "aa") == false);
}

TEST_CASE("testing format") {
    CHECK(format("name=%s age=%d", "aa", 18) == "name=aa age=18");
}

TEST_CASE("testing gbk2utf8") {
    std::string gbk_str("heheda\xce\xd2\xca\xc7\xd0\xa1\xd6\xedni123", 20);
    std::string utf8_str("heheda\xe6\x88\x91\xe6\x98\xaf\xe5\xb0\x8f\xe7\x8c\xaani123", 24);
    std::string res = gbk2utf8(gbk_str);
    CHECK(res == utf8_str);
}

TEST_CASE("testing utf82gbk") {
    std::string gbk_str("heheda\xce\xd2\xca\xc7\xd0\xa1\xd6\xedni123", 20);
    std::string utf8_str("heheda\xe6\x88\x91\xe6\x98\xaf\xe5\xb0\x8f\xe7\x8c\xaani123", 24);
    std::string res = utf82gbk(utf8_str);
    CHECK(res == gbk_str);
}
