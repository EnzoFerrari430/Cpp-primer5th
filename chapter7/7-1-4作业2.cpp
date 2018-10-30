#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Sales_data;
istream &read(istream &,Sales_data &);


struct Sales_data
{
    Sales_data();
    string bookNo;
    unsigned units_sold;
    double revenue;
    //类内部的变量不允许在定义时初始化,使用构造函数

    Sales_data(istream &is){read(is,*this);}
    string isbn() const {return bookNo;}
};

Sales_data::Sales_data()
{
    units_sold = 0;
    revenue = 0.0;
}

istream &read(istream &is,Sales_data &item)
{
    is>>item.bookNo>>item.units_sold>>item.revenue;
    return is;
}

int main()
{
    Sales_data total(cin);
    if( !total.isbn().empty() )
    {
        istream &is = cin;
        while(is)
        {
            Sales_data trans(is);  //按ctrl+z能进到这一步
            if(total.isbn() == trans.isbn())
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
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
        cerr<<"NO data!"<<endl;
        return -1;
    }
    return 0;
}
