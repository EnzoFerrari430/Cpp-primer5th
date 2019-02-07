#include <iostream>
using namespace std;
/*
派生类的成员或友元只能通过派生类对象来访问基类的受保护成员
派生类对于一个基类对象中的受保护成员没有任何访问特权
*/
class Base
{
protected:
    int prot_mem;  //protected成员
};

class Sneaky : public Base
{
    friend void clobber(Sneaky&);  //能访问Sneaky::prot_mem
    friend void clobber(Base&);  //不能访问Base::prot_mem
    int j;  //class 默认是private的
};

void clobber(Sneaky &s){s.j = s.prot_mem = 0;}  //能通过派生类访问基类

//void clobber(Base &b){b.prot_mem = 0;}  //Base::prot_mem是protected  不能直接访问基类
//派生类的成员和友元只能通过派生类对象访问派生类对象中基类部分的受保护成员，而不能直接对基类对象中的成员进行访问




/*
类对继承而来的成员的访问权限影响因素：
    1.基类中该成员的访问说明符
    2.派生类的派生列表中的访问说明符
*/

class Base2
{
public:
    void pub_mem(){cout<<"pub_mem() Base2"<<endl;}  //public成员
protected:
    int prot_mem;  //protected成员
private:
    char priv_mem;  //private成员
};

class Pub_Derv : public Base2
{
public:
    //正确： 派生类能访问protected成员
    int f(){return prot_mem;}
    //错误： private成员对于派生类来说是不可访问的
    //char g(){return priv_mem;}
};

class Prot_Derv : protected Base2
{
public:
    int f2()const {return prot_mem;}
};

class Priv_Derv : private Base2
{
public:
    //private  不影响派生类的访问权限
    int f1() const {return prot_mem;}

    //pub_mem()能被继承，也能被调用，但是派生说明符指示该函数在这里是private的，相当于下面的写法
/*
private:
    Base2::pub_mem();
*/
};

/*
    派生访问说明符还可以控制继承自派生类的新类的访问权限
*/
class Derived_from_Public : public Pub_Derv
{
public:
    //正确： Base::prot_mem在Pub_Derv中仍是protected的
    int use_base(){return prot_mem;}
};

class Derived_from_Private : public Priv_Derv
{
    //错误： Base::prot_mem在Priv_Derv中的private的
    //int use_base(){return prot_mem;}
};

int main()
{
    //派生访问说明符的目的是控制派生类用户（包括派生类的派生类在内）对于基类成员的访问权限
    //说白了就是d2中基类部分的访问都是private的，d1中基类部分的访问都是public的
    Pub_Derv d1;  //继承自Base成员是public的
    Priv_Derv d2; //继承自Base的成员是private的

    d1.pub_mem();  //正确： pub_mem在派生类中是public的
    //d2.pub_mem();  //错误： pub_mem在派生类中是private的     私有成员不能直接调用
    Prot_Derv d3;
    //d3.pub_mem();  //相当于外部用户直接调用这个受保护的成员
    return 0;
}
