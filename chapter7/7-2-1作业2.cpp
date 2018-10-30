#include <iostream>
#include <string>
using namespace std;
/*
    类的作者常常需要定义一个辅助函数，比如add　read  print等。尽管这些函数定义的操作从概念上来说属于类的接口的组成部分，但是不属于类本身

    定义非成员函数的方式与定义其他函数一样，通常把函数的声明和定义分离开来。如果函数在概念上属于类但是不定义在类中，
    则它一般与类声明在同一个头文件内,这样，用户使用接口的任何部分都只需要引入一个文件
*/
struct Sales_data
{
    friend Sales_data add(const Sales_data &,const Sales_data &);
    friend std::ostream &print(std::ostream &,const Sales_data &);
    friend std::istream &read(std::istream &,Sales_data &);

public:
    //新成员：关于Sales_data对象的操作
    string isbn() const{return bookNo;}
    Sales_data &combine(const Sales_data &);  //模仿赋值运算，所以用引用当成左值返回
    double avg_price() const;


private:
    //数据成员
    string bookNo;
    unsigned units_sold = 0;  //★网上资料都说类的成员变量定义不允许直接初始化   这里有疑问
    double revenue = 0;
};

//Sales_data的非接口成员函数
Sales_data add(const Sales_data &,const Sales_data &);
std::ostream &print(std::ostream &,const Sales_data &);
std::istream &read(std::istream &,Sales_data &);

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;  //把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this;  //返回调用该函数的对象
}

double Sales_data::avg_price() const
{
    double avg = 0;
    avg = revenue / units_sold;
    return avg;
}

std::istream &read(std::istream &is,Sales_data &item)
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main()
{
    Sales_data item;
    read(cin,item);
    print(cout,item);

    return 0;
}
