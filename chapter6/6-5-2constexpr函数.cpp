#include <iostream>
#include <string>
using namespace std;

/*
    C++11
    constexpr函数是指能用于常量表达式的函数。
    constexpr几项约定:
        函数的返回类型及所有形参类型都是字面值类型
        函数体重必须有且只有一条return语句

        constexpr不一定返回常量表达式

*/
constexpr int new_sz()
{
    return 42;
}

constexpr int foo = new_sz();
//编译时，验证new_sz函数返回的是常量表达式
//执行时，编译器把对constexpr函数的调用替换成其结果值。为了能在编译过程中随时展开。constexpr函数被隐式指定为内联函数
int main()
{
    cout<<foo<<endl;

    return 0;
}
