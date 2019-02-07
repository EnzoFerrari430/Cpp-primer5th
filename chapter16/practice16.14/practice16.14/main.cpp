#include <Windows.h>
#include "Screen.h"
using namespace std;
int main()
{
	Screen<5, 5> scr('c');
	Screen<5, 5> sccr;

	//output src to screen
	std::cout << scr << std::endl;

	std::cout << sccr << std::endl;
	//input connet to the src
	std::cin >> sccr;

	std::cout << sccr << endl;

	system("pause");
	return 0;
}