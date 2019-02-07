#include <iostream>
#include <string>
using namespace std;
class Sales_data
{

    friend Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);
    friend ostream& operator<<(ostream &,const Sales_data&);
    friend istream& operator>>(istream &,Sales_data & );
public:
    //Sales_data(string s = string(),unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}//6.5.1默认实参中有写到，如果某个形参被赋予了默认值，则它后面的所有形参都必须有默认值
    Sales_data():bookNo(""),units_sold(0),revenue(0){}
    Sales_data(string s,unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}
    Sales_data(const Sales_data&);  //拷贝构造函数
    Sales_data& operator=(const Sales_data&);  //拷贝赋值运算符
    Sales_data(Sales_data &&)noexcept;  //移动构造函数
    Sales_data& operator=(Sales_data&&)noexcept;  //移动赋值运算符
    ~Sales_data() {}
    Sales_data& operator+=(const Sales_data&);

    string isbn()const
    {
        return bookNo;
    }

private:
    inline double avg_price()const;
    //数据成员
    string bookNo;
    unsigned int units_sold;
    double revenue;
};

inline double Sales_data::avg_price()const
{
    return units_sold? revenue/units_sold : 0;
}

Sales_data::Sales_data(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
}

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    if( this != &rhs )
    {
        bookNo = rhs.bookNo;
        units_sold = rhs.units_sold;
        revenue = rhs.revenue;
    }
    return *this;
}

Sales_data::Sales_data(Sales_data &&rhs)noexcept
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
}

Sales_data& Sales_data::operator=(Sales_data &&rhs)noexcept
{
    if( this != &rhs )
    {
        bookNo = std::move(rhs.bookNo);
        units_sold = rhs.units_sold;
        revenue = rhs.revenue;
    }
    return *this;

}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data ss(lhs);
    ss += rhs;
    return ss;
}

ostream& operator<<(ostream &output,const Sales_data &rhs)
{
    //output<<rhs.isbn()<<" "<<rhs.units_sold<<" "<<rhs.revenue<<" "<<rhs.avg_price();
    output<<rhs.isbn()<<" "<<rhs.units_sold<<" "<<rhs.revenue<<" "<<rhs.avg_price();
    return output;
}

istream& operator>>(istream &input,Sales_data &rhs)
{
    double price;  //不需要初始化，因为我们将先读数据到price，之后才使用它
    input>>rhs.bookNo>>rhs.units_sold>>price;
    if(input )  //检查是否输入成功
    {
        rhs.revenue = rhs.units_sold * price;
    }
    else
    {
        rhs = Sales_data();  //输入失败：对象被赋予默认的状态
    }
    return input;
}




int main()
{
    Sales_data s1("C++",100,100);
    Sales_data s2("PHP",100,10);
    Sales_data s3("C++",10,80);
    Sales_data s4;
    cin>>s4;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s1+s3<<endl;

    return 0;
}
