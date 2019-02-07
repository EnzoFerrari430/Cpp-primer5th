#pragma once
#include <iostream>
#include <typeinfo>
/*
一个类(无论是普通函数还是类模板)可以包含本身是模板的成员函数。
这种成员被称为成员模板。
！！成员模板不能是虚函数
*/

//普通(非模板)类的成员模板
class DebugDelete
{
public:
	DebugDelete(std::ostream& s = std::cerr):os(s){}
	//与任何函数模板相同,T的类型有编译器推断
	template <typename T>
	void operator()(T* p)const
	{
		os << "deleting unique_ptr: " << typeid(T).name() << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};