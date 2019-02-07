#pragma once
#ifndef CLASSMEM_H_
#define CLASSMEM_H_
#include <functional>
/*
我们通过作用域运算符:: 来访问static成员和类型成员
在非模板的代码中，编译器知道类的定义。因此它知道通过作用域运算符访问的名字是类型还是static成员
例如：string::size_type,编译器有string定义，从而知道size_type是一个类型

但是当T是一个模板类型参数时，编译器在遇到T::mem这样的代码时，就懵逼了。
因为编译器不知道mem是一个类型成员还是一个static数据成员

例如:
	T::size_type *p;
	如果size_type是T的类型成员，则p是一个指针
	如果size_type是T的静态变量，则该表达式是一个size_type与名为p的变量的相乘
为了解决上述问题，我们就必须显示的告诉编译器该名字是一个类型
*/

template <typename T>
typename T::size_type top(const T& c)
{
	if (!c.empty())
	{
		return c.back();
	}
	else
		return typename T::value_type();
}

/*
就像我们能为函数参数提供默认实参一样，我们也可以提供默认模板实参。
在C++11新标准中，我们可以为函数和类模板提供默认实参。
早版本只允许为类模板提供默认实参。
*/
//重写compare
template <typename T,typename F = less<T>>  //F是函数类型
int compare(const T& v1, const T& v2, F f = F())
{
	if (f(v1, v2))
		return -1;
	if (f(v2, v1))
		return 1;
	return 0;
}
#endif