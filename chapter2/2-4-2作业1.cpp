#include <iostream>

int main()
{
    //a
    //int i = -1,&r = 0;  错误 &r引用在定义的时候必须初始化，而且初始化一定是一个对象

    //c
    const int i = -1,&r = 0;

    //b
    int i2;
    int *const p2 = &i2;

    //d
    const int *const p3 = &i2;

    //e
    const int *p1 = &i2;  //不用在定义的时候非要初始化

    //f
    //int ii = 0;
    //const int &const r2 = ii;  //引用必须初始化 而且const不能在引用符号&后，因为引用不是一个对象

    //g
    const int i3 = i,&r1 = i;  //right r1也是一个const的引用

    //int const *p = &i;

    //const int const *p4 = &i2;  VS2008通过

    return 0;
}
