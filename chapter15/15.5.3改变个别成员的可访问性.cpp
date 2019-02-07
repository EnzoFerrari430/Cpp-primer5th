#include <iostream>
using namespace std;

/*
    有时我们可以通过using声明改变派生类继承的某个名字的访问级别

*/

class Base
{
public:
    std::size_t size()const{return n;}
protected:
    std::size_t n;
};

class Derived : private Base  //注意，private继承
{
public:
    //保持对象尺寸相关的成员的访问级别
    using Base::size;  //将继承来的size()  提升成public
protected:
    using Base::n;  //将继承而来的n  提升成protected
};
//  ！！！派生类只能为那些它可访问的名字提供声明

int main()
{


    return 0;
}
