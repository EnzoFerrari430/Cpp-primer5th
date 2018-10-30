#include <iostream>
using namespace std;
//定义一个返回数组的指针或引用的函数比较烦琐，但是有一些方法可以简化这一任务，其中最直接的方法是使用类型别名
typedef int arrT[10];  //arrT是一个类型别名，它表示的类型是含有10个整数的数组

using arrT = int[10]; //arrT的等价声明

arrT *func(int i);  //func函数返回一个指向含有10个整数的数组的指针
//arrT是含有10个整数的数组的别名，因为无法返回数组，所以将返回类型定义成数组的指针


//声明一个返回数组指针的函数
//要想在声明func时不用类型别名。我们必须牢记被定义的名字后面数组的维度
//返回数组指针的形式  type(*function(parameter_list))[dimension]
//例子
int (*func(int i))[10];

//C++11新标准简化上述func声明方法，使用尾置返回类型
int main()
{
    int arr[10];
    int *p1[10];
    int (*p2)[10] = &arr;
    //和这些声明一样，要想定义一个返回数组指针的函数，则数组的维度必须跟在函数名字后面



    return 0;
}
