#include <iostream>
#include <Windows.h>
#include "Sales_data.h"
using namespace std;

int main()
{
    Sales_data s1("C++",10,55.5);
    Sales_data s2("C++",20,68);
    cout<<s1+s2<<endl;
    s2 += s1;
    cout<<s2<<endl;
	cout << compare(s1, s2) << endl;
	/*
	�������
		Sales_data��û������<������
	*/
    cout << "Hello world!" << endl;
	system("pause");
    return 0;
}
