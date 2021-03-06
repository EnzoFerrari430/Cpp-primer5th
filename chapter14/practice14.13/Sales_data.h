#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

#include <iostream>
#include <string>
class Sales_data
{
public:

    friend Sales_data operator-(const Sales_data &,const Sales_data &);
    friend Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);
    friend std::ostream& operator<<(std::ostream &,const Sales_data&);
    friend std::istream& operator>>(std::istream &,Sales_data & );
public:
    //Sales_data(string s = string(),unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}//6.5.1默认实参中有写到，如果某个形参被赋予了默认值，则它后面的所有形参都必须有默认值
    Sales_data(std::string s,unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}
    Sales_data():bookNo(""),units_sold(0),revenue(0){}
    Sales_data(const std::string &s):Sales_data(s,0,0.0f){}
//    Sales_data(const Sales_data&);  //拷贝构造函数
//    Sales_data& operator=(const Sales_data&);  //拷贝赋值运算符
//    Sales_data(Sales_data &&)noexcept;  //移动构造函数
//    Sales_data& operator=(Sales_data&&)noexcept;  //移动赋值运算符
    ~Sales_data() {}
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);

    std::string isbn()const
    {
        return bookNo;
    }

private:
    inline double avg_price()const;
    //数据成员
    std::string bookNo;
    unsigned int units_sold;
    double revenue;
};
Sales_data operator-(const Sales_data &,const Sales_data &);
Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);
std::ostream& operator<<(std::ostream &,const Sales_data&);
std::istream& operator>>(std::istream &,Sales_data & );

inline double Sales_data::avg_price() const
{
    return units_sold?  revenue / units_sold : 0;
}

#endif // SALES_DATA_H_INCLUDED
