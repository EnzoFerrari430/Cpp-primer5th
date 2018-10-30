#include <iostream>
#include <string>
using namespace std;
/*
    构造函数不能被声明成const

    类通过一个特殊的构造函数来控制默认初始化过程,这个函数就是默认构造函数

    如果我们没有显式的定义构造函数，那么编译器就会为我们隐式的定义一个默认构造函数
    编译器创建的构造函数又称为合成的默认构造函数，有如下规则
        1.如果存在类内的初始值，用它来初始化成员
        2.否则默认初始化该成员
*/

struct Sales_data
{
    //新增的构造函数
    Sales_data() = default;  //C++11新标准 如果我们希望默认构造函数的作用完全等同于合成的默认构造函数，可以在参数列表后面写上 = default
    Sales_data(const string &s): bookNo(s){}
    //冒号以及冒号和花括号之间的部分称为构造函数初始值列表,负责为新创建的对象的一个或多个数据成员赋初值
    Sales_data(const string &s,unsigned n,double p): bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(istream &);

    //其他已有的成员
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &);
    double avg_price() const ;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{


    return 0;
}
