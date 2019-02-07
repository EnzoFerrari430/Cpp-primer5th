#include "Sales_data.h"

namespace cplusplus_primer
{
	//Sales_data成员及重载运算符的定义
	Sales_data& Sales_data::operator+=(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}

	//Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
	//{
	//	Sales_data item = lhs;
	//	item += rhs;
	//	return item;
	//}
}


//命名空间的成员，可以在内部定义也可以在外部定义
cplusplus_primer::Sales_data cplusplus_primer::operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data item = lhs;
	item += rhs;
	return item;
}