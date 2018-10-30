#include <iostream>
#include <string>
#include <typeinfo>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    int ia[3][4] = {0};
    int (*p)[4] = ia;  //p是一个指针 指向含有4个整数的数组
    p = &ia[2];  //p指向ia的尾元素
    /*
        int *ip[4];  整型指针的数组
        int (*ip)[4];  指向含有4个整数的指针

        使用C++11新标准提出的auto decltype就能尽可能避免在数组前面加上一个指针类型了
    */

    /*
        使用类型别名也能简化多维数组的指针
    */

    //将4个整型组成的数组命名为int_array
    using int_array = int[4];  //新标准下的类型别名声明
    cout<<typeid(int_array).name()<<endl;  //A4_i
    typedef int int_array[4];  //等价的typedef声明
    //输出元素
    for(int_array *p = ia;p != ia+3; p++)
    {
        for(int *q = *p;q != *p +4;q++)
        {
            cout<<*q<<' ';
        }
        cout<<endl;
    }

    return 0;
}
