#include <iostream>
#include "scpp/time/time.h"
using namespace scpp;


int main()
{
	Time t1;
	t1.show();

	std::cout << t1.format("%Y-%m-%d %H:%M:%S") << std::endl;

	Time::sleep(2000);

	Time t2;

	double usec = t2 - t1;
	std::cout << usec / 1000.0 << "ms" << std::endl;

	return 0;
}
