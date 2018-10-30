#inlcude <iostream>
#include <string>
using namespace std;
/*
    调用函数一般比求等价表达式要慢一些。
    内联函数可以避免函数调用的开销

    将函数指定为内联函数(inline)，通常就是将它在每个调用点上"内联的"展开
    内联机制用于优化规模较小，流程直接，频繁调用的函数。很多编译器都不支持内联递归函数，而且一个多行的函数也不大可能在调用点内联的展开

*/

inline const string &shorterString(const string &s1,const string &s2)
{
    return s1.size() <= s2.size()? s1: s2;
}

int main()
{

    //当调用如下函数
    cout<<shorterString(s1,s2)<<endl;
    //在编译过程中展开成类似下面的形式
    cout<<(s1.size() <= s2.size()? s1: s2 )<<endl;
    //从而消除了shorterString函数运行时的开销

    return 0;
}
