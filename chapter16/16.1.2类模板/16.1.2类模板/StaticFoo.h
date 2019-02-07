#pragma once
#include <iostream>
#include <string>
/*
类模板可以声明static成员
*/


template <typename T>
class Foo
{
public:
	static std::size_t count() { return ctr; }
private:
	static std::size_t ctr;
};
//对任意给定类型X，都有一个Foo<X>::ctr和一个Foo<X>::count
//所有Foo<X>类型的对象共享相同的ctr对象和count函数

//类模板的每个static数据成员必须有且仅有一个定义
template <typename T>
size_t Foo<T>::ctr = 0;  //定义并初始化0

//实例化static成员Foo<std::string>::ctr和一个Foo<std::string>::count
Foo<std::string> fs;
//所有三个对象共享相同的Foo<int>::ctr和一个Foo<int>::count
Foo<int> fi1, fi2, fi3;

//访问模板类的静态成员1.通过类类型对象来访问一个类模板的static成员	2.使用作用域运算符直接访问成员
Foo<int> fi;
auto ct1 = Foo<int>::count();  //通过作用域运算符访问
auto ct2 = fi.count();		//通过类类型对象访问
//ct = Foo::count();  没有指定类模板Foo的模板参数列表
