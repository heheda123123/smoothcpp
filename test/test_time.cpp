#include <iostream>
#include "scpp/time/time.h"
using namespace scpp;


int main()
{
	std::cout << "test display time\n";
	Time t1;
	t1.show();
	std::cout << t1.format("%Y-%m-%d %H:%M:%S") << std::endl;

	std::cout << "test sleep 500ms\n";
	Time t2;
	Time::sleep(500);
	Time t3;
	std::cout << t3 - t2 << std::endl;

	std::cout << "test reset and elapse\n";
	t1.reset();
	Time::sleep(500);
	std::cout << "t1 reset elapse " << t1.elapse() << std::endl;
	

	return 0;
}
