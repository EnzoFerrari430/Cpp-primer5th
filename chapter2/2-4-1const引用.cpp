#include <iostream>

/*
与普通引用不同的是，对常量的引用不能被用作修改它所绑定的对象

引用的类型必须和其所引用对象的类型一致但是有2种特殊的情况
1.在初始化常量引用时，允许用任意表达式作为初始值


*/

int main()
{
    const int ci = 1024;
    const int &r1 = ci;  //引用及其对应的对象都是常量
    //r1 = 42;  //r1是对常量的引用不能修改值
    //int &r2 = ci;  //非常量的引用不能指向一个常量对象


    char c = 42;
    double d = 3.14;
    const int &r3 = c;  //情况一
    /*
        这里会先生成一个临时的整型常量,然后再让r3绑定这个临时量
        const int temp = c;
        const int &r3 = temp;
    */
    const int &r4 = d;
    //int &r5 = d;
    //int &r5 = c;  //这是普通的非常量引用
    std::cout<<r3<<std::endl;
    std::cout<<r4<<std::endl;
    std::cout<<d<<std::endl;

    return 0;
}
