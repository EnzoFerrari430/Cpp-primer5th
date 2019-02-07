#include <iostream>
using namespace std;
/*
    含有（或者未经覆盖直接继承）纯虚函数的类是抽象基类


    如果基类定义了虚函数，而派生类连声明都没有，则基类的虚函数会被当成一个普通函数对待，派生类简单的继承了该函数
*/

class base
{
public:
    virtual fun()const
    {
        cout<<"virtual function in class base"<<endl;
    }
};

class derived : public base
{
public:
    //virtual fun()const;
};

int main()
{
    derived d;
    d.fun();
    base b1;
    base *b2 = &b1;
    b2->fun();
    b2 = &d;
    b2->fun();

    return 0;
}
