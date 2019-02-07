#include <iostream>
using namespace std;

/*
    当为派生类定义拷贝或移动构造函数时，我们通常使用对应的基类构造函数初始化对象的基类部分。
*/

class Base
{

};

class D : public Base
{
public:
    //默认情况下，基类的默认构造函数初始化对象的基类部分。
    //要想使用拷贝或移动构造函数，我们必须在构造函数初始值列表中显示的调用该构造函数
    D(const D& d):Base(d);  //拷贝基类成员，然后再拷贝派生类的成员

    D(D&& d):Base(std::move(d))noexcept;  //移动基类成员,然后再移动派生类的成员

    //派生类的赋值运算符也必须显示的为其基类赋值
    D& operator=(const D&);

};

/*
    如果拷贝构造函数只是如下这么写的话
    D(const D& d);
    D对象的基类部分会使用  Base的默认构造函数  来初始化,
    D的成员会从其他对象那里拷贝数据来

    如果想要拷贝或移动基类的部分，则必须在派生类的拷贝构造函数中加入初始值列表来显示的调用基类的拷贝或移动构造函数
*/

//Base::operator=(const Base&)  该函数不会被自动调用
D& D::operator=(const D& rhs)
{
    Base::operator=(rhs);  //为其基类部分赋值
    //再按照之前的方式为派生类的成员赋值
    return *this;
}


int main()
{

    return 0;
}
