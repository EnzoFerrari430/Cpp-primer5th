#include <iostream>
#include <string>
using namespace std;

/*
这里typedef double A被类型参数A隐藏了，因此tmp不是一个double
*/
typedef double A;
template <typename A,typename B>
void f(A a,B b)
{
    A tmp = a;
    double B;  //因为我们不能重用模板参数名，所以这里声明名字为B的变量是错误的

    //cout<< a << " " << b <<endl;
}

//由于参数名不能重用，所以一个模板参数名在一个特定模板参数列表中只能出现一次
//template <typename V,typename V>  //这里已经定义了一次了
//void f()
//{
//
//
//}

//与函数参数相同，声明中的模板参数的名字不必与定义中的相同
template <typename T> T clac(const T&,const T&);

template <typename Type>
Type clac(const Type& lhs,const Type& rhs)
{
    cout<<"hello world"<<endl;
    return lhs;
}

int main()
{
    f(1,2);
    clac(1,2);


    return 0;
}
