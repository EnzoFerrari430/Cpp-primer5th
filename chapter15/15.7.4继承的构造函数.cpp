#include <iostream>
using namespace std;
/*
    一个类只能初始化它的直接基类，出于同样的原因，一个类也只能继承其直接基类的构造函数

    使用方法是提供一条注明了直接基类名的using语句

    当把using语句作用于构造函数时，using声明语句将令编译器产生代码
*/

class Base
{
public:
    Base(){cout<<"Base construction"<<endl;}
};

class Derived : public Base
{
public:
    using Base::Base;  //继承Base的构造函数
};

int main()
{
    Base b;
    Derived d;



    return 0;
}
