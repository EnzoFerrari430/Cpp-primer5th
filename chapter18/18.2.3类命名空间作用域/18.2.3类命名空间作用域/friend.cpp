#include "friend.h"

namespace FRIEND
{

	void f2()
	{
		std::cout << "FRIEND::f2" << std::endl;
	}

	void f(const C&)
	{
		std::cout << "FRIEND::f" << std::endl;
	}

}