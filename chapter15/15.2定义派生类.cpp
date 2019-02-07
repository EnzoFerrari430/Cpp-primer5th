#include <iostream>
using namespace std;
/*
    最终的派生类将包含它的直接基类的子对象以及每个间接基类的子对象

*/

class A
{
public:
    A(int aa = 0):a(aa){}
public:
    int a;
};

class B :public A
{
public:
    B(int aa = 0,int bb = 0):A(aa),b(bb){}
public :
    int b;
};

class C : public B
{
public:
    C(int aa = 0,int bb = 0,int cc = 0):B(aa,bb),c(cc){}
public:
    int c;
};

/*
    C++11新特性提供一种防止继承发生的方法
    即在类名后面跟一个关键字final
*/

class NoDerived final  //  NoDerived不能作为基类
{

};

class Base
{

};

class Last final : Base  //Last不能作为基类
{

};

class Bad : NoDerived  //错误NoDerived是final
{

};

class Bad2:Last  //错误 Last是final的
{

};

int main()
{
    C c(1,2,3);
    cout<<c.a<<" "<<c.b<<" "<<c.c<<endl;
    cout<<sizeof(A)<<endl;  //4
    cout<<sizeof(B)<<endl;  //8
    cout<<sizeof(C)<<endl;  //12  最终的派生类将包含它的直接基类的子对象以及每个间接基类的子对象

    return 0;
}
