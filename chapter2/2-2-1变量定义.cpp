#include <iostream>

/*
初始化不是赋值，初始化是指创建变量时赋予其一个初始化的值
而赋值是把对象当前的值擦除，用一个新的值代替他

定义任何函数体外的变量被初始化为0
*/


int main()
{
    //都可以进行初始化
    int units_sold1 = 0;
    int units_sold2 = {0};
    int units_sold3{0};
    int units_sold4(0);

    long double ld = 3.1415926536;

    int a{ld},b = {ld};  //用列表的形式初始化会报错
    int c(ld),d = ld;



    return 0;
}
