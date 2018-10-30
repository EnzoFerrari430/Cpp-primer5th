#include <iostream>
#include <string>
using namespace std;
/*
    当我们使用重载函数时，上下文必须清晰的界定到底应该选用哪个函数
    编译器通过指针类型决定选用哪个函数，指针类型必须与重载函数中的某一个精确匹配
*/
void ff(int *);
void ff(unsigned int);

void (*pf1)(unsigned int) = ff;

//void (*pf2)(int) = ff;  //错误 没有任何一个ff与该形参匹配
//double (*pf3)(int *) = ff;  //错误 ff和pf3的返回类型不匹配


//函数指针形参
//★和数组类似，虽然不能定义函数类型的形参，但是形参可以是指向函数类型的指针

//第三个形参是函数类型，它会自动地转换成指向函数的指针
void useBigger(const string &s1,const string &s2,bool pf(const string &,const string &));
//等价声明  显式的将形参定义成指向函数的指针
void useBigger(const string &s1,const string &s2,bool (*pf)(const string &,const string &));

//为了避免直接使用函数指针类型而造成的冗长，可以使用类型别名和decltype
//Func和Func2是函数类型
typedef bool Func(const string &,const string &);
typedef decltype(lengthCompare) Func2;  //等价的类型

//FuncP和FuncP2是指向函数的指针
typedef bool (*FuncP)(const string &,const string &);
typedef decltype(lengthCompare) *FuncP2;  //等价的类型
int main()
{

    //可以直接把函数作为实参使用，此时它会自动转换成指针
    //自动将函数lengthCompare转换成指向该函数的指针
    useBigger(s1,s2,lengthCompare);

    return 0;
}
