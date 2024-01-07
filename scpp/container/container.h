#include <algorithm>

namespace scpp
{
	template <typename Container, typename T>
	bool contains(const Container& container, const T& value) {
		return std::find(container.begin(), container.end(), value) != container.end();
	}
}