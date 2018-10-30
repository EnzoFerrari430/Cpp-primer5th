#include <iostream>

/*
    常量表达式是指值不会改变而且在编译过程中就能得到计算结果的表达式
    字面值就属于常量表达式,用常量表达式初始化的const对象也是常量表达式

*/

int main()
{
    //对象是不是常量表达式由它的数据类型和初始值决定
    const int max_files = 20;  //max_files是常量表达式
    const int limit  = max_files + 1;  //limit是常量表达式
    int staff_size = 27;  //staff_size不是常量表达式  初始值是一个字面值常量但是类型不是const int
    //const int sz = get_size();  不是常量表达式


    //C++11标准   声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化
    constexpr int mf = 20;  //
    constexpr int li = mf + 1;
    //constexpr int sz = size();  只有当size()是一个constexpr函数时才是一条正确的语句

    //constexpr的指针初始值必须是nullptr 或0，或者是存储在一个固定地址中的对象
    const int *p = nullptr;  //指向整型常量的指针
    constexpr int *q = nullptr;  //常量指针  constexpr把定义的对象置为了 顶层const

    int null = 0,*p1 = &null;

    return 0;
}
