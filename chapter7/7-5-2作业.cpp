#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
public:
    Sales_data(){cout<<"默认构造函数"<<endl;}
    Sales_data(string s,unsigned cnt,double pc):bookNo(s),units_sold(cnt),price(pc){cout<<"3参数构造函数"<<endl;}

    Sales_data(string s):Sales_data(){cout<<"委托1构造函数"<<endl;}
    Sales_data(string s,unsigned cnt):Sales_data(s,cnt,33){cout<<"委托2构造函数"<<endl;}  //无需重复定义s和cnt

    string bookNo;
    unsigned units_sold = 0;
    double price = 0;

};

int main()
{
    Sales_data C;

    /*
    当一个构造函数委托给另一个构造函数时，受委托的构造函数的初始值列表和函数体都依次被执行。在Sales_data类中，受委托的构造函数的初始值列表
    和函数体被一次执行。在Sales_data类中，受委托的构造函数体恰好是空的。假如函数体包含有代码的话，将先执行这些代码，然后控制权才会交还给
    委托者的函数体
    */
    Sales_data book2("C++");
    Sales_data book3("python",5);

    return 0;
}
