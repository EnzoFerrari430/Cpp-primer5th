#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Sales_data
{
    string isbn() const
    {
        return bookNo;
    }
    Sales_data &combine(const Sales_data &);  //模仿赋值运算，所以用引用当成左值返回
    double avg_price() const;

    //数据成员
    string bookNo;
    unsigned units_sold;  //★网上资料都说类的成员变量定义不允许直接初始化   这里有疑问
    double revenue;
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

std::istream &read(std::istream &is,Sales_data &item)  //普通引用，因为要对这个对象写入值
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item)  //常量引用，只需要读取这个对象 不需要写操作
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
    Sales_data total;
    if(read(cin,total))
    {
        Sales_data trans;
        while(read(cin,trans))
        {
            if(total.isbn() == trans.isbn())
            {
                add(total,trans);
            }
            else
            {
                print(cout,total);
                total = trans;
            }
        }
        cout<<total.isbn()<<" "<<total.units_sold<<" "<<total.revenue<<" "<<total.avg_price();
    }
    else
    {
        cerr<<"no data!"<<endl;
    }
    return 0;
}
