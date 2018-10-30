#include <iostream>
/*
指针和引用不同，指针使对象引用不是，所以允许把指针本身定位常量
**常量指针必须初始化
一旦初始化完成，它的值(存放在指针中的那个地址)就不能改变了
把*放在const之前说明指针是一个常量


*/


int main()
{
    int errNumb = 0;
    int *const curErr = &errNumb;  //这个指针一直指向errNumb,这个指针是一个只读的变量
    //curErr是常量但是 *curErr不是常量 可以改变


    std::cout<<*curErr<<std::endl;
    *curErr = *curErr + 1;  //但是可以用过curErr指针改变errNumb值
    std::cout<<*curErr<<std::endl;


    const double pi = 3.14159;
    const double *const pip = &pi;  //pip是指向常量对象的常量指针



    return 0;
}
