#include "Sales_data.h"


std::istream& operator>>(std::istream &input,Sales_data &rhs)
{
    double price;
    input>>rhs.bookNo>>rhs.units_sold>>price;
    if(input)
    {
        rhs.revenue = rhs.units_sold * price;
    }
    else
    {
        rhs = Sales_data();
    }
    return input;
}

std::ostream& operator<<(std::ostream &output,const Sales_data &rhs)
{
    output<<rhs.isbn()<<" "<<rhs.units_sold<<" "<<rhs.revenue<<" "<<rhs.avg_price();
    return output;
}

Sales_data operator-(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data item = lhs;
    item.units_sold -= rhs.units_sold;
    item.revenue -= rhs.revenue;
    return item;
}

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data item = lhs;
    item.units_sold += rhs.units_sold;
    item.revenue += rhs.revenue;
    return item;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -=rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}


