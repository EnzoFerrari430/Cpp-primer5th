#include "Sales_data.h"

namespace cplusplus_primer
{
	//Sales_data��Ա������������Ķ���
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


//�����ռ�ĳ�Ա���������ڲ�����Ҳ�������ⲿ����
cplusplus_primer::Sales_data cplusplus_primer::operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data item = lhs;
	item += rhs;
	return item;
}