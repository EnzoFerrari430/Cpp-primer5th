#include <iostream>
using namespace std;

class Base
{
public:
    void pub_mem(){cout<<"pub_mem() Base"<<endl;}  //public成员
protected:
    int prot_mem;  //protected成员
private:
    char priv_mem;  //private成员
};

class Pub_Derv : public Base
{
public:
    void memfcn(Base &b){b = *this;}
    //正确： 派生类能访问protected成员
    int f(){return prot_mem;}
    //错误： private成员对于派生类来说是不可访问的
    //char g(){return priv_mem;}
};

class Prot_Derv : protected Base
{
public:
    void memfcn(Base &b){b = *this;}
    int f2()const {return prot_mem;}
};

class Priv_Derv : private Base
{
public:
    void memfcn(Base &b){b = *this;}
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
    void memfcn(Base &b){b = *this;}
    //正确： Base::prot_mem在Pub_Derv中仍是protected的
    int use_base(){return prot_mem;}
};

class Derived_from_Protected : public Prot_Derv
{
public:
    void memfcn(Base &b){b = *this;}
    //错误： Base::prot_mem在Priv_Derv中的private的
    //int use_base(){return prot_mem;}
};

class Derived_from_Private : public Priv_Derv
{
public:
    //practice15.19  这个不行,其他的都可以访问  Priv_Derv是private派生来的，则Priv_Derv类中的Base成员都是private的，派生类不能访问基类的私有成员
    //void memfcn(Base &b){b = *this;}

    //错误： Base::prot_mem在Priv_Derv中的private的
    //int use_base(){return prot_mem;}
};


int main()
{
    Pub_Derv d1;
    Base *p = &d1;  //d1的类型是Pub_Derv
    //正确

    Priv_Derv d2;
    //p = &d2;  //d2的类型是Priv_Derv
    //不正确

    Prot_Derv d3;
    //p = &d3;  //d3的类型是Prot_Derv
    //不正确

    Derived_from_Public dd1;
    p = &dd1;  //dd1的类型是Derived_from_Public
    //正确

    Derived_from_Private dd2;
    //p = &dd2;  //dd2的类型是Derived_from_Private
    //不正确

    Derived_from_Protected dd3;
    //p = &dd3;  //dd3的类型是Derived_from_Protected
    //不正确

    //书中544页明确指出，只有当派生类公有的继承自基类时，用户代码才能使用派生类向基类的转换

    return 0;
}
