#define NDEBUG  //这个放在最前面
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;


//assert宏常用于检查"不能发生"的条件
//assert的行为依赖于一个名为NDEBUG的预处理变量的状态。如果定义了NDEBUG，则assert什么也不做。默认状态下没有定义NDEBUG，此时会执行运行时检查
//定义NDEBUG能避免检查各种条件所需的运行时开销，当然此时根本就不会执行运行时检查.因此assert应该仅用于验证那些确实不可能发生的事情。


void print(const int ia[],size_t size)
{
#ifndef NDEBUG
    //__func__ 是编译器定义的一个局部静态变量，用于存放函数的名字
    cerr<<__func__<<":array size is "<<size<<endl;
#endif // NDEBUG
}
//__func__输出当前调试的函数的名字。编译器为每个函数都定义了 _ _func_ _ 它是const char的一个静态数组，用于存放函数名字
//C++编译器除了定义 _ _func_ _之外，预处理器还定义了另外4个对于程序调试很有用的名字
//__FILE__   存放文件名的字符串字面值
//__LINE__   存放当前行号的整型字面值
//__TIME__   存放文件编译时间的字符串字面值
//__DATE__   存放文件编译日期的字符串字面值


int main()
{
    string s1;
    cin>>s1;
    assert(s1.size() > 10);

    if(s1.size() < 10)
        cerr<<"Error: "<<__FILE__<<" : in function "<<__func__<<" at line "<<__LINE__<<endl<<"      Compiled on "<<__DATE__<<" at "<<__TIME__<<endl<<"     Word read was \""<<s1<<"\": Length too short"<<endl;

    cout<<s1<<endl;



    return 0;
}
