#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Sales_data
{
    //新成员：关于Sales_data对象的操作
    string isbn() const{return bookNo;}
    //在成员函数内部，我们可以直接使用调用该函数的对象的成员，而无需通过访问运算符来做到这一点
    //isbn隐式的使用this指向成员 相当于 return this->bookNo;
    //请求该函数的对象的地址初始化this

    //参数列表之后的const关键字,这里的作用是修改隐式this指针的类型
    //默认情况下this的类型是指向类类型非常量版本的常量指针
    //在Sales_data成员函数中，this的类型是Sales_data *const  this保存的地址不能改，但是*this可以改.
    //所以在默认情况下this指针不能绑定到一个常量对象上
    //所以要把this指针声明成 const Sales_data *const，以提高函数的灵活性
    //因为this不在参数列表中，所以C++语法允许把const关键字放在成员函数的参数列表之后
    //这样this就成了指向常量的指针，所以isbn可以读取它的对象的成员 但是不能写入新值
    //这里的const用于判断

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

int main()
{
    const int a = 42;
    const int *p = &a;



    return 0;
}
