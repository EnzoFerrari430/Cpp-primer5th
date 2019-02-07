#include <iostream>
using namespace std;
/*
有2种情况可能会产生多重转换路径
    1.两个类提供了相同的类型转换
    2.类定义了多个转换规则，最典型的就是算术运算符，最好只定义最多一个与算术类型有关的转换规则

*/

//第一种多重转换路径
struct B;
struct A
{
    A() = default;
    A(const B&);  //把一个B转换成A
    //其他数据成员
};
struct B
{
    operator A()const ;  //也是把一个B转换成A
    //其他数据成员
};

A f(const A&);  //声明一个函数
B b;
A a = f(b);  //这里会产生二义性 不知道要调用  f(B::operator A())  还是  f(A(const B&))
//如果真的要这么使用就直接显式的调用,这个二义性是没有办法用强制类型转换来实现的


//第二种多重转换路径
//如果类定义了一组类型转换
struct AA
{
    AA(int = 0);
    AA(double);
    operator int()const;  //最好不要创建2个转换对象都是算术类型的类型转换
    operator double()const;
};

void f2(long double);
AA aa;
f2(aa);

long lg;
AA aa2(lg);
//上述这2种产生二义性的根本原因是他们所需的标准类型转换级别一致
//如果转换类型包含标准类型的转换，则标准类型转换的级别将决定编译器选择最佳的匹配过程。

int main()
{


    return 0;
}
