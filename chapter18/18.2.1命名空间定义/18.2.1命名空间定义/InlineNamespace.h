#pragma once
#include <iostream>
/*
内联命名空间中的名字可以直接被外层命名空间直接使用。
我们无须在内联命名空间的名字前添加表示该命名空间的前缀，
通过外层命名空间的名字就可以直接访问它

*/

//关键字inline必须出现在命名空间第一次定义的地方，后续再打开命名空间的时候可以写inline也可以不写
namespace inspace
{
	inline namespace FifthEd
	{
		class Query_base
		{
		public:
			Query_base() { std::cout << "inspace::FifthEd::Query_base: hello world" << std::endl; }
		};
	}

	namespace FourthEd
	{
		class Item_base
		{
		public:
			Item_base() { std::cout << "inspace::FourthEd::Item_base: hello world" << std::endl; }
		};
		class Query_base
		{
		public:
			Query_base() { std::cout << "inspace::FourthEd::Query_base: hello world" << std::endl; }
		};
	}
}
