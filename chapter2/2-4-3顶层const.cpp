#include <iostream>
#include <stdio.h>
/*
    顶层const表示指针本身是一个常量
    底层const表示指针所指的对象是一个常量

*/
int main()
{
    int i = 0;
    int *const p1 = &i;  //顶层const p1的值不能改变
    const int ci = 42;   //顶层const 可以表示任意的对象是常量
    const int *p2 = &ci; //允许改变p2的值，这是一个底层const
    const int *const p3 = p2;  //第一个const是一个底层const 第二个const是一个顶层const
    //const int *const p3 = &i;
    const int &r = ci;   //用于声明引用的都是底层const  const和r之间还有一个&符

    //在执行对象的拷贝操作时，顶层const不受影响
    i = ci;
    //ci = i
    p2 = p3;  //指向对象的类型相同  顶层const不影响

    //底层const有限制，执行对象的拷贝操作时，拷入和拷出的对象必须具有相同的底层const资格
    //或者两个对象的数据类型必须能够转换,一般非常量可以转换成常量
    //int *p = p3;  常量不能转换成非常量
    p2 = p3;
    p2 = &i;  //正确，非常量可以转换成常量
    //int &r = ci; 常量不能转换成非常量
    const int &r2 = i;  //正确，非常量可以转换成常量


    return 0;
}
