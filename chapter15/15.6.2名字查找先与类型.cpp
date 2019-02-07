#include <iostream>
using namespace std;

/*
    如果派生类（内层作用域）的成员与基类（外层作用域）的某个成员同名，
    则派生类将在其作用域内隐藏该基类成员。即使派生类成员和基类成员的形参列表不一致，基类也会被隐藏
*/
class Base
{
public:
    int memfcn();
};

class Derived : public Base
{
public:
    int memfcn(int);  //隐藏基类的memfcn
};

int main()
{
    Derived d;
    Base b;
    b.memfcn();
    d.memfcn(10);
    //d.memfcn();  参数列表为空的memfcn被隐藏了
    d.Base::memfcn();



    return 0;
}
