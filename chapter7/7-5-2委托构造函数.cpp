#include <iostream>
#include <string>

/*
    C++11新标准扩展了构造函数初始值的功能：委托构造函数
    一个委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程

    一个委托构造函数也有一个成员初始值列表和一个函数体
*/


using namespace std;

class Sales_data
{
public:
    //非委托构造函数
    Sales_data(string s,unsigned cnt,double price):bookNo(s),units_sold(cnt),revenue(cnt*price){}
    //其余的构造函数全都委托给另一个构造函数
    Sales_data():Sales_data("",0,0){}

    Sales_data(string s):Sales_data(s,0,0){}

    Sales_data(istream &is):Sales_data(){read(is,*this);}
};

int main()
{


    return 0;
}
