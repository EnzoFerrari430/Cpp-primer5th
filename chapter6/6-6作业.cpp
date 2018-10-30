#include <iostream>
using namespace std;

void f()
{
    cout<<"nothing"<<endl;
}
void f(int a1)
{
    cout<<"int"<<endl;
}
void f(int a1,int a2)
{
    cout<<"2int"<<endl;
}
void f(double a1,double a2 = 3.14)
{
    cout<<"2double"<<endl;
}

//6.53
int clac(int &a1,int &a2)
{
    cout<<"int&"<<endl;
}

int clac(const int &a1,const int &a2)
{
    cout<<"const int&"<<endl;
}

int clac(char *a1,char *a2)
{
    cout<<"char*"<<endl;
}
int clac(const char *a1,const char *a2)
{
    cout<<"const char*"<<endl;
}
int clac(char *const a1,char *const a2)  //这是顶层const,指针本身是一个常量
{
    cout<<"char *const"<<endl;
}
int main()
{
    //6.49 候选函数是函数名一致，而且在调用点可用
    //可行函数是 形参数量与本次调用提供的实参数量相等，每个实参的类型与对应的形参类型相同,或者能转换成形参类型

    //6.50
    //f(2.56,42);  二义性
    f(42);
    f(42,0);  //f3 f4都可行，f3是最佳匹配
    f(2.56,3.14);  //f3 f4都可行，f4是最佳匹配




    return 0;
}
