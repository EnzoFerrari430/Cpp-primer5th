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

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    Sales_data total;
    if(cin>>total.bookNo>>total.units_sold>>total.revenue)
    {
        Sales_data trans;
        while(cin>>trans.bookNo>>trans.units_sold>>trans.revenue)
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout<<total.bookNo<<' '<<total.units_sold<<' '<<total.revenue<<endl;
                total = trans;
            }
        }
        cout<<total.bookNo<<' '<<total.units_sold<<' '<<total.revenue<<endl;
    }
    else
    {
        cerr<<"no data!"<<endl;
    }
    return 0;
}
