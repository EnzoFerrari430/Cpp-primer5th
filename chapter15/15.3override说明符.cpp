#include <iostream>
using namespace std;
/*
    派生类如果定义了一个函数与基类中虚函数的名字相同但是形参列表不同，这仍是合法的行为。
    编译器将认为新定义的这个函数与基类中原有的函数相互独立的。这时，派生类没有覆盖掉基类中的版本。

    这种声明基本都是程序员自己手误写错了形参列表。

    而且这种错误一般调试比较难发现。

    在C++11新标准中，我们可以使用override关键字来说明派生类中的虚函数。

    这样程序更加清晰，同时编译器也可以为我们发现一些错误。
*/

class B
{
public:
    virtual void f1(int)const;
    virtual void f2();
    void f3();
};

void B::f1(int a)const
{
    cout<<"virtual function f1 in Class B"<<endl;
}

void B::f2()
{
    cout<<"virtual function f2 in Class B"<<endl;
}

void B::f3()
{
    cout<<"normal function f3 in Class B"<<endl;
}

class D1 : public B
{
public:
    virtual void f1(int) const override;  //正确：  f1与基类中的f1匹配  const也要记得加上
    //virtual void f2(int)override;         //错误：  B没有形如f2(int)的函数
    //virtual void f3()override;            //错误：  f3不是虚函数
    //virtual void f4()override;            //错误：  B没有名为f4的函数
};

void D1::f1(int a)const  //  !!!override在外部定义时不用加
{
    cout<<"virtual function f1 in Class D1"<<endl;
}

/*
    我们还能把某个函数指定为final，如果我们已经把函数定义成final了，则之后的任何尝试覆盖该函数的操作都将引发错误
*/

class D2 : public B
{
public:
    //从B类继承f2()和f3()函数，覆盖f1(int)
    virtual void f2()override;  //所有的虚函数必须有定义
    virtual void f1(int)const final;  //不允许后续的其他类覆盖f1(int)

};

void D2::f1(int a)const
{
    cout<<"final virtual function f1 in Class D2"<<endl;
}

void D2::f2()
{
    cout<<"virtual function f2 in Class D2"<<endl;
}

/*
虚函数与默认实参
    如果我们通过基类的引用或者指针调用函数，则使用基类中定义的默认实参。
    即使实际运行的是派生类的函数版本，传入派生类函数的默认实参依旧是基类定义的默认实参
*/

class Base
{
public:
    virtual void fun(int a = 10) const;  //原始的虚函数不用加override
};

void Base::fun(int a)const
{
    cout<<"virtual function fun in Class Base. And the number a is : "<<a<<endl;
}

class Derived : public Base
{
public:
    virtual void fun(int a = 20) const override;
};

void Derived::fun(int a)const
{
    cout<<"virtual function fun in Class Derived. And the number is : "<<a<<endl;
}

/*
回避虚函数机制
    在某些情况下，我们希望对虚函数的调用不要进行动态绑定，而是强迫其执行虚函数的某个特定版本
    使用作用域运算符可以实现这一目的
*/

int main()
{
    B b;
    D1 d1;
    b.f1(0);
    d1.f1(0);
    D2 d2;
    d2.f1(0);
    d2.f2();
    d2.f3();

    cout<<endl;
    cout<<endl;
    Base base;
    Derived derived;
    Base *pbase;
    pbase = &base;
    pbase->fun();
    pbase = &derived;  //如果我们通过基类的引用或者指针调用函数，则使用基类中定义的默认实参。
    pbase->fun();
    //回避虚函数机制
    //这里pbase已经指向了派生类derived
    pbase->Base::fun();


    return 0;
}
