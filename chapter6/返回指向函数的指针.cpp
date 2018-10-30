#include <iostream>
#include <string>
using namespace std;
/*
    和数组类似，虽然不能返回一个函数，但是能返回指向函数类型的指针。然而，必须把返回类型写成指针的形式，
    编译器不会自动的将函数返回类型当成对应的指针类型


*/
//想要声明一个返回函数指针的函数，最简单的办法就是使用类型别名
using F = int(int *,int);    //F是函数类型，不是指针
using PF = int(*)(int *,int);//PF是指针类型


PF f1(int);
//F f1(int);  //错误  f1作为函数不能返回函数
F *f1(int); //正确    显式的指定返回类型是指向函数的指针

//当然 也能直接声明
int (*fi(int))(int *,int);

//尾置返回类型
auto f1(int)->int (*)(int *,int);


//将auto和decltype用于函数指针类型
string::size_type sumLength(const string &,const string &);
string::size_type largerLength(const string &,const string &);
//根据其形参的取值，getFcn函数返回指向sumLength或者largerLength的指针
decltype(sumLength) *getFcn(const string &);


int main()
{

    return 0;
}
