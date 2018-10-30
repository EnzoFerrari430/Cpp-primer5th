#include <iostream>
#include <string>
#include <vector>
using namespace std;
//public说明符之后的成员在整个程序内可被访问，public成员定义类的接口
//private说明符之后的成员可以被类的成员函数访问,但是不能被该类的代码访问，private部分封装类的实现细节
class Sales_data
{
public:  //访问控制说明符
    Sales_data() = default;
    Sales_data(const string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(const string &s):bookNo(s){}
    Sales_data(istream &);
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &);
private:  //访问控制说明符
    double avg_price() const {return units_sold? revenue / units_sold:0;}
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
//作为接口，构造函数和部分成员函数紧跟在public说明符之后
//而数据成员和作为实现部分的函数则跟在private说明符后面

/*
    class和struct的区别
    struct和class的默认访问权限不太一样
    类可以在它的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于类的定义。
        如果使用的是struct关键字，则定义在第一个访问说明符之前的成员是public，相反的，如果使用class关键字，则这些成员是private
*/

int main()
{


    return 0;
}
