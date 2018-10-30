#include <iostream>
/*
顶层const 表示指针本身是个常量

底层const 表示指针所指的对象是一个const


*/



int main()
{
    //int i, *const cp;  const指针一定要初始化
    //定义一个int型的i 和int型的const指针，但是cp没有初始化

    //int *p1,*const p2;  同上const指针一定要初始化

    //const int ic,&r = ic;  const int ic中ic一定要初始化

    //const int *const p3;  const指针一定要初始化

    //const int *p;  //成功

    /*
    const int ic = 42;
    int *p1;
    p1 = &ic;
    wrong  ic是const int型指针不能是int * 应该是const int *p1
    */

    /*
    const int ic = 42;
    const int *const p3 = &ic;
    成功
    */

    /*
    const int ic = 42;
    const int *const p3;
    ic = *p3;
    p3需要初始化 而且ic的值不能改变
    */

    return 0;
}
