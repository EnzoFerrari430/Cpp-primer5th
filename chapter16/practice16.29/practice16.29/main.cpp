#include <iostream>
#include <Windows.h>
#include "Blob.h"
using namespace std;

int main()
{
	Blob<int> bi = { 1,2,3,4,5,6 };
	cout << bi[3] << endl;

	UP<int> u1(new int(42));
	cout << *u1 << endl;
	UP<int> u2(u1.release());
	cout << *u2 << endl;

	system("pause");
	return 0;
}