#pragma once
#include <string>
/*
一个类也可以将另一个模板的每个实例都声明为自己的友元，或者限定特定的实例为友元
*/

//前置声明，在将模板的一个特供实例声明为友元时要用到
template <typename T> class Pal;
class C  //C是一个普通的非模板类
{
	friend class Pal<C>;  //用类C实例化的Pal是C的一个友元
	//Pal2的所有实例都是C的友元，这种情况无需前置声明
	template <typename T> friend class Pal2;
};

template <typename T>
class C2  //C2是一个类模板
{
	//C2的每个实例将相同实例化的Pal声明为友元
	friend class Pal<T>;  //Pal的模板声明必须在作用域内
	//Pal2的所有实例都是C2的每个实例的友元，不需要前置声明
	template <typename X> friend class Pal2;
	//Pal3是一个非模板类，它是C2所有实例的友元
	friend class Pal3;
};

//令模板自己的类型参数成为友元
//在C++11新标准中，我们可以将模板类型参数声明为友元
template <typename Type>
class Bar
{
	friend Type;  //将访问权限授予用来实例化Bar的类型
};

//虽然我们不能定义一个typedef引用一个模板。比如typedef Blob<T>
//但是C++11新标准允许我们为类模板定义一个类型别名
template <typename T> using twin = pair<T, T>;
twin<std::string> authors;  //authors是一个pair<string,string>

//当我们定义一个模板类型别名时，可以固定一个或多个模板参数
template <typename T> using partNo = pair<T, unsigned>;
partNo<std::string> books;  //books是一个pair<std::string,unsigned>