#include <iostream>
using namespace std;
/*
    派生类向基类的转换允许给基类的拷贝移动操作传递一个派生类的对象
    由于这些操作不是虚函数，所以当我们给基类的构造函数传递一个派生类对象时，实际运行的构造函数是基类中定义的那个
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

int main()
{
    C c(1,2,3);
    A a1(c);  //构造函数只能处理基类自己的成员,而忽略掉了c中的成员b和c
    A a2 = c;  //赋值运算符同样只能处理基类自己的成员，而忽略掉了c中的成员b和c
    cout<<a1.a<<endl;
    cout<<a2.a<<endl;

    return 0;
}
