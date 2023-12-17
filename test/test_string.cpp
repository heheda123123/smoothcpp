#include <iostream>

#include "scpp/string/string.h"
using namespace scpp;


int main()
{
	std::cout << ltrim("hello world", "eh") << std::endl;
	std::cout << rtrim("hello world", "drl") << std::endl;
	std::cout << capitalize("hello world") << std::endl;
	std::cout << format("name=%s age=%d", "jack", 18) << std::endl;
	return 0;
}
