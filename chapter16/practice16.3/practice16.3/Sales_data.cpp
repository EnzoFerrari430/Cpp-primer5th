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
    item += rhs;
    return item;
}

/*
//14.21  +执行实际的加法操作
Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data item(lhs.isbn(),0,0);
    item.units_sold = lhs.units_sold + rhs.units_sold;
    item.revenue = lhs.revenue + rhs.revenue;
    return item;
}

//14.21  +=调用+  这种写法在性能上没有优势，而且可读性不好
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    *this = *this + rhs;
    return *this;
}
*/

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

bool operator==(const Sales_data &lhs,const Sales_data &rhs)
{
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs,const Sales_data &rhs)
{
    return !(lhs == rhs);
}

/*
//practice 14.22参考答案写法，个人不是很赞同
Sales_data &Sales_data::operator=(const std::string &s)
{
    //相当于就是isbn写错了，修正一下
    bookNo = s;
    return *this;
}
*/

//此版本，相当于重新更新了一个书名
Sales_data &Sales_data::operator=(const std::string &s)
{
    *this = Sales_data(s);
    return *this;
}

