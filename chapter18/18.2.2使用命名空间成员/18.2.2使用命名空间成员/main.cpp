#include <iostream>
#include <Windows.h>
using std::cout;
using std::endl;
/*
using指示示例
*/

namespace blip
{
	int i = 16, j = 15, k = 23;
}

int j = 0;

void manip()
{
	//using指示,blip中的名字被"添加"到全局作用域中
	//using指示是令整个命名空间的所有内容变得有效。
	//因此using指示一般被看做是出现在最近的外层作用域中
	using namespace blip;  //如果使用了j,则将在::j和blip::j之间产生冲突
	++i;
	/*
	blip的成员看起来好像是定义在blip和manip所在的作用域一样.
	当命名空间被注入到它的外层作用域之后，很可能该命名空间中定义的名字会与其外层作用域中的成员冲突
	这种冲突是允许存在的，但是想要使用冲突的名字，我们就必须明确指出名字的版本
	*/
	//++j;
	++::j;
	++blip::j;
	/*
	using指示一般被看做是出现在最近的外层作用域中
	因此blip::k类似于一个全局变量
	在manip函数内部被k这个局部变量隐藏了起来
	*/
	int k = 97;
	++k;

	cout << i << endl;
	cout << ::j << endl;
	cout << blip::j << endl;
	cout << blip::k << endl;
	cout << k << endl;
}


int main()
{
	manip();
	system("pause");
	return 0;
}