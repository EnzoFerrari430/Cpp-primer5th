#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>
using namespace std;

/*
一个非类型参数表示一个值而非一个类型。
我们通过一个特定的类型名而非关键字class或typename来指定非类型参数

在调用compare("hi", "mom")时
编译器会实例化如下版本
int compare(const char (&p1)[3],const char (&p2)[4])
*/

template <int N, int M>
int compare(const char(&p1)[N], const char(&p2)[M])
{
	cout << N << " " << M << endl;
	return strcmp(p1, p2);
}


//这样就不用对数组形参传递一个指出大小的形参了
template <int N, int M>
int compareInt(const int(&p1)[N], const int(&p2)[M])
{
	cout << N << " " << M << endl;
	return 0;
}

/*
函数模板可以声明成inline或者constexpr的，如同非模板函数一样。
inline或constexpr说明符放在模板参数列表之后，返回类型之前。
*/
//正确：inline说明符跟在模板参数列表之后
template <typename T> inline T Mymin(const T&, const T&);
//错误：inline说明符的位置不正确
//inline template<typename T> T min2(const T&, const T&);


/*
编写类型无关的代码:模板程序应该尽量减少对实参类型的要求
	1.模板中的函数参数是const的引用
		通过将函数参数设定为const的引用，我们保证了函数可以用于不能拷贝的类型。
	2.函数体中的条件判断仅使用<比较运算
		只使用<判断降低了compare函数对要处理的类型的要求

如果要真的考虑类型无关和可移植性，可能需要用到less
*/
template <typename T> int compare2(const T &v1, const T &v2)
{
	if (less<T>()(v1, v2))
		return -1;
	if (less<T>()(v2, v1))
		return 1;
	return 0;
}

/*
函数模板和类模板成员函数的定义通常放在头文件中
*/

int main()
{
	compare("hi", "mom");

	compareInt({ 1, 2, 3 }, { 4, 5, 6 });
	int a[10] = { 1,2,3,4,5 };
	int b[5] = { 1,3,5,7,9 };
	compareInt(a,b);

	system("pause");
	return 0;
}
