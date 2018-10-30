#include <iostream>
#include <fstream>
using namespace std;

struct Sales_data
{
    //新成员：关于Sales_data对象的操作
    string isbn() const
    {
        return bookNo;
    }

    Sales_data &combine(const Sales_data &);  //模仿赋值运算，所以用引用当成左值返回
    double avg_price() const;

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

std::istream &read(std::istream &is,Sales_data &item)
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

double Sales_data::avg_price() const
{
    double avg = 0;
    avg = revenue / units_sold;
    return avg;
}

std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}

int main(int argc,char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);

    Sales_data total;
    if(read(input,total))
    {
        Sales_data trans;
        while(read(input,trans))
        {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output,total)<<endl;
                total = trans;
            }
        }
        print(output,total)<<endl;
    }
    else
    {
        cerr<<"No data!"<<endl;
    }


    return 0;
}
