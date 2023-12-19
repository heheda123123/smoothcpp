#include <iostream>
#include "scpp/string/string.h"

using namespace scpp;


int main()
{
    std::cout << to_lower("aAaAAbb") << "\n";
    std::cout << to_upper("aaaAAbb") << "\n";

    std::cout << ltrim("hello world", "eh") << std::endl;
    std::cout << rtrim("hello world", "drl") << std::endl;
    std::cout << trim("hello world", "held") << std::endl;

    auto a = split_str("name=%s age=%d aaaaaaaaa", "=%");
    std::cout << to_string(a) << std::endl;

    auto b = split_chars("name=%s age=%d aaaaaaaaa", "=s");
    std::cout << to_string(b) << std::endl;

    auto c = split_str("aaaa bbbb cccc");
    auto d = join(b, " ");
    std::cout << "c " << to_string(c) << "\n";

    std::vector<int> testformat = {1, 2, 34};
    std::cout << to_string(testformat) << "\n";

    std::cout << has_prefix("jjjaaa", "jj") << std::endl;
    std::cout << has_suffix("jjjaaa", "jj") << std::endl;

    
    std::cout << contains("jjjjzzzbbb", "zzz") << "\n";
    
    std::cout << format("name=%s age=%d", "jack", 18) << std::endl;

    auto amap = std::map < std::string, int> {{"1", 2}, {"3", 4}, {"5", 6}};
    std::cout << to_string(amap) << std::endl;

    return 0;
}
