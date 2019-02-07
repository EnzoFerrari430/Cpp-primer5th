#include "specialtemplate.h"

template <> struct std::hash<Sales_data>
{
	size_t operator()(const Sales_data& s)const
	{
		return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
	}
};