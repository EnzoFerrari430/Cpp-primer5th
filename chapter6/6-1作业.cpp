#include <iostream>
using namespace std;
int power3(int n)
{
    int num = 1;
    int i ;
    for(i = 0 ;i<3;i++)
    {
        num *= n;
    }
    return num;
}
int main()
{
    /*
        6.1形参就是函数在定义的时候，形式上的参数，用于告诉人们这个函数需要的参数
           实参就是运用函数的时候要实际使用的参数

        6.2a 函数的返回类型不一致
        6.2b 函数没有返回类型
        6.2c 函数形参不能重名
        6.2d 函数的函数体必须用"{}"括起来
    */

    //6.3
    cout<<power3(10)<<endl;

    return 0;
}
