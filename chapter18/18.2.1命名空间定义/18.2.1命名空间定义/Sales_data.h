#pragma once
#include <iostream>
/*
多个库将名字放置在全局命名空间中将引发命名空间污染
通过命名空间防止名字冲突提供更加可控的机制

只要能出现在全局作用域中的声明就能置于命名空间内，
主要包括:类、变量(及其初始化操作)、函数(及其定义)、模板和命名空间

命名空间的名字也必须在定义它的作用域内保持唯一:  不能在命名空间内重复定义

命名空间是可以不连续的:
	如果之前没有名为PJD的命名空间，则上述代码创建一个新的命名空间
	否则上述代码打开已经存在的命名空间定义并为其添加一些新成员的声明


命名空间的组织方式类似于我们管理自定义类及函数的方式:
	1.头文件中的命名空间的作用是定义类，以及声明作为类接口的函数及对象
	2.命名空间成员的定义部分则置于另外的源文件中
*/

namespace PJD
{
	class A
	{
	public:
		A() { std::cout << "A: hello world" << std::endl; }
	};
}

namespace PJD
{
	class B
	{
	public:
		B() { std::cout << "B: hello world" << std::endl; }
	};
}

namespace cplusplus_primer
{
	class Sales_data
	{
	public:
		Sales_data(std::string s, unsigned int u, double price) :bookNo(s), units_sold(u), revenue(u * price) {}
		Sales_data() :bookNo(""), units_sold(0), revenue(0) {}
		Sales_data& operator+=(const Sales_data&);
	public:
		//数据成员
		std::string bookNo;
		unsigned int units_sold;
		double revenue;
	};
	Sales_data operator+(const Sales_data&, const Sales_data&);


	//命名空间可以嵌套

	//第一个嵌套的命名空间:定义了库的Query部分
	namespace QueryLib
	{
		class Query
		{

		};

		Query operator&(const Query&, const Query&);
	}

	//第二个嵌套的命名空间:定义了库的Sales_data部分
	namespace BookStore
	{
		class Quote
		{

		};

		class Disc_quote : public Quote
		{

		};
	}
}

