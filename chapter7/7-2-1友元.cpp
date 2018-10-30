#include <iostream>
#include <string>
#include <vector>
using namespace std;

//类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的友元
//如果类想把一个函数作为它的友元，只需增加一条以friend关键字开头的函数声明语句
class Sales_data
{
    //  为Sales_data的非成员函数所做的友元声明

    friend Sales_data add(const Sales_data &,const Sales_data &);
    friend std::istream &read(std::istream &,Sales_data &);
    friend std::ostream &print(std::ostream &,const Sales_data &);

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

Sales_data add(const Sales_data &,const Sales_data &);
std::istream &read(std::istream &,Sales_data &);  //IO类属于不能被拷贝的类型，因此只能通过引用来传递它们
std::ostream &print(std::ostream &,const Sales_data &);

int main()
{


    return 0;
}
