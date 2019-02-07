#include <iostream>
#include <Windows.h>
#include "Tep.h"
#include "classmem.h"
using namespace std;

/*
一个模板参数名的可用范围是在其声明之后，至模板声明或定义结束之前。
模板参数会隐藏外层作用域中声明的相同名字。
但是与大多数其他上下文不同，在模板内不能重用模板参数名
*/
//typedef double A;
//template <typename A,typename B> void f(A a, B b)
//{
//	A tmp = a;
//	double B;
//	cout << tmp << " " << b << endl;
//}

int main()
{

	f(1, 2);

	//当用户调用这个版本的compare时，可以提供自己的比较操作，但这并不是必须的
	bool i = compare(0, 42);  //使用less；i为-1
	//Sales_data item1(cin), item2(cin);
	//bool j = compare(item1, item2, compareIsbn);



	system("pause");
	return 0;
}