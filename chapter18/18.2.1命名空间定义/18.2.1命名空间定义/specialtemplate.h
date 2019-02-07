#pragma once
#include "Sales_data.h"
using namespace cplusplus_primer;
/*
	模板特例化必须定义在原始模板所属的命名空间中。
	只要我们在命名空间中声明了特例化，就能在命名空间外部定义它
*/

//我们必须将模板特例化声明成std的成员
namespace std
{
	//使用模板特例化需要在命名空间声明它
	template <> struct hash<Sales_data>;
}