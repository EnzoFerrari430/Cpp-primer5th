#include <iostream>
#include <Windows.h>
#include <string>
#include "tmp.h"
#include "friend.h"
/*
实参相关的查找和类类型相关形参
std::string s;
std::cin>>s;
如我们所知的，该调用等价于
operator>>(std::cin,s);
operator>>函数定义在标准库string中，string又定义在命名空间std中
所以我们应该要如下调用
std::operator>>(std::cin,s);
或者
using std::operator>>
operator>>(std::cin,s);
但是这里都不需要!!!


对于命名空间中名字的隐藏规则来说有一个重要的例外，它使得我们可以直接访问输入输出运算符。
这个例外是，当我们给函数传递一个类类型的对象时，除了在常规的作用域查找之外还会查找实参类所属的命名空间
这一例外对于传递类的引用或指针的调用同样有效

*/

using namespace A;
int main()
{

	//std::cout << f2() << std::endl;

	std::string s;
	operator >> (std::cin, s);
	//当编译器发现对operator>>的调用时，首先在当前的作用域中寻找合适的函数
	//接着查找输出语句的外层作用域。
	//随后，因为>>表达式的形参是类类型，所以编译器还会查找cin和s的类所属的命名空间
	operator<<(std::cout, s);
	std::cout << std::endl;


	FRIEND::C obj;
	//当编译器发现对f的调用时，首先在当前的作用域中寻找合适的函数
	//接着查找外层作用域。
	//随后，因为f函数的形参是类类型，所以编译器还会查找obj的类所属的命名空间
	f(obj);
	//f2();


	system("pause");
	return 0;
}