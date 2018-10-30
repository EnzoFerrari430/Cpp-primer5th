#include <iostream>

int main()
{
    extern int i;  //声明i而非定义i
    int j;  //声明并且定义了j

    //如果声明的变量加了初始值，那么extern的作用就没了
    //extern double pi = 3.1416 ;  //定义,而且在函数体内部初始化extern关键字标记的变量，会引发错误

    //int catch-22;  错误标识符

    return 0;
}
