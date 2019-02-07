#include <iostream>
#include <string>

namespace primerLib
{
    //fun1
    void compute()
    {
        std::cout<<"function with no parameter in namespace primerLib"<<std::endl;
    }
    //fun2
    void compute(const void* a)
    {
        std::cout<<"function with parameter1: const void* in namespace primerLib"<<std::endl;
    }
}

//using primerLib::compute;
/*
using声明在这里的话
命名空间primerLib中的fun1和fun2函数会在全局作用域中可见
所以函数f的候选函数有5个
而可行函数有4个，除去fun1
只有fun3是精确匹配
所以会调用fun3
*/
//fun3
void compute(int a)
{
    std::cout<<"function with parameter1: int in global"<<std::endl;
}
//fun4
void compute(double a,double b = 3.4)
{
    std::cout<<"function with parameter1: double and parameter2: double in global"<<std::endl;
}
//fun5
void compute(char* a,char* b = 0)
{
    std::cout<<"function with parameter1: char* and parameter2: char* in global"<<std::endl;
}

void f()
{
    using primerLib::compute;
    /*
    原文p702:using声明的，它的有效范围从using声明的地方开始，一直到using声明所在的作用域结束为止。
    在此过程中，外层作用域的同名实体将被隐藏

    所以，如果在这里的话全局作用域中的三个compute函数会被隐藏
    候选函数只有fun1和fun2
    可行函数只有fun2，需要隐式转换实参方可匹配
    */
    compute(0);
}

int main()
{
    f();

    return 0;
}
