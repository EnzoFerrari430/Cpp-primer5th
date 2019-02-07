#include "unnamedspace.h"
namespace space1
{
	namespace
	{
		void swap(int *a, int *b)
		{
			int temp = *a;
			*a = *b;
			*b = temp;
		}

		void swapprint(int n1, int n2)
		{
			std::cout << "before n1 = " << n1 << "n2 = " << n2 << std::endl;
			swap(&n1, &n2);
			std::cout << "after n1 = " << n1 << "n2 = " << n2 << std::endl;
		}
	}

}
