#include <iostream>

int main()
{
    int i = 0;
    const int v2 = 0;  //顶层const
    int v1 = v2;  //顶层const可以用来拷贝
    int *p1 = &v1,&r1 = v1;  //都是非常量
    const int *p2 = &v2;  //v2是一个顶层const 所以不影响
    const int *const p3 = &i;  //i是一个非常量
    const int &r2 = v2;  //底层const，支持非常量转换成常量


    r1 = v2;  //正确,r1是v1的引用，v2是顶层const
    //p1 = p2;  //错误,p2是一个底层const，不支持从常量转换成为非常量
    p2 = p1;  //正确,p2是一个底层const，p1是非常量，支持从非常量转换成常量
    //p1 = p3;  //错误,p3左部是一个底层const p1是非常量，不支持从常量转换成非常量
    p2 = p3;  //正确，2个都是底层const

    return 0;
}
