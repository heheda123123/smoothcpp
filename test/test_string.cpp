#include <iostream>
#include "scpp/string/string.h"

using namespace scpp;


int main()
{
    std::cout << to_lower("aAaAAbb") << "\n";
    std::cout << to_upper("aaaAAbb") << "\n";

    std::cout << ltrim("hello world", "eh") << "\n";
    std::cout << rtrim("hello world", "drl") << "\n";
    std::cout << trim("hello world", "held") << "\n";

    auto a = split_str("name=%s age=%d aaaaaaaaa", "=%");
    std::cout << to_string(a) << "\n";

    auto b = split_chars("name=%s age=%d aaaaaaaaa", "=s");
    std::cout << to_string(b) << "\n";

    auto c = split_str("aaaa bbbb cccc");
    auto d = join(b, " ");
    std::cout << "c " << to_string(c) << "\n";

    std::vector<int> testformat = {1, 2, 34};
    std::cout << to_string(testformat) << "\n";

    std::cout << has_prefix("jjjaaa", "jj") << "\n";
    std::cout << has_suffix("jjjaaa", "jj") << "\n";

    
    std::cout << contains("jjjjzzzbbb", "zzz") << "\n";
    
    std::cout << format("name=%s age=%d", "jack", 18) << "\n";

    auto amap = std::map < std::string, int> {{"1", 2}, {"3", 4}, {"5", 6}};
    std::cout << to_string(amap) << "\n";

    return 0;
}
