#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Sales_data;
istream &read(istream &,Sales_data &);

struct Sales_data
{

    string bookNo;
    unsigned units_sold = 1;
    double price = 5;
    double revenue;

    Sales_data() = default;  //默认构造函数;
    Sales_data(const string &s,unsigned n):bookNo("C++"),units_sold(3){}

    Sales_data(const string &s):bookNo("STL"){}
    Sales_data(const string &s,unsigned n,double p){bookNo = s; units_sold = n;price = p;}

    Sales_data(istream &is)
    {
        read(is,*this);
    }
};

std::istream &read(std::istream &is,Sales_data &item)  //普通引用，因为要对这个对象写入值
{
    is>>item.bookNo>>item.units_sold>>item.price;
    item.revenue = item.price * item.units_sold;
    return is;
}

int main()
{
    Sales_data p1("C");
    Sales_data p2;  //string 默认为空
    Sales_data p3("java",2,3.14);
    Sales_data p4("C++",123);
    Sales_data p5(cin);
    cout<<p1.bookNo<<' '<<p1.units_sold<<' '<<p1.price<<endl;
    cout<<p2.bookNo<<' '<<p2.units_sold<<' '<<p2.price<<endl;
    cout<<p3.bookNo<<' '<<p3.units_sold<<' '<<p3.price<<endl;
    cout<<p4.bookNo<<' '<<p4.units_sold<<' '<<p4.price<<endl;
    cout<<p5.bookNo<<' '<<p5.units_sold<<' '<<p5.price<<endl;
    return 0;
}
