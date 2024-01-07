#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename Container, typename T>
bool contains(const Container& container, const T& value) {
	return std::find(container.begin(), container.end(), value) != container.end();
}

int main() {
	// 示例用法
	std::vector<int> intVector = {1, 2, 3, 4, 5};
	std::list<std::string> stringList = {"apple", "orange", "banana"};

	int targetInt = 3;
	std::string targetString = "kiwi";

	if (contains(intVector, targetInt)) {
		std::cout << "The vector contains " << targetInt << std::endl;
	} else {
		std::cout << "The vector does not contain " << targetInt << std::endl;
	}

	if (contains(stringList, targetString)) {
		std::cout << "The list contains " << targetString << std::endl;
	} else {
		std::cout << "The list does not contain " << targetString << std::endl;
	}

	return 0;
}
