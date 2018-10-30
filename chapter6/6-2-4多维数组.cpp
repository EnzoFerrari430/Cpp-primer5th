#include <iostream>
using namespace std;

//matrix指向数组的首元素，该数组的元素是由10个整数构成的数组
void print(int (*matrix)[10],int rowSize)
{

}

//与上面的形式等价。 matrix看起来是一个二维数组，但是实际上形参是指向含有10个整数的数组的指针
void print(int matrix[][10],int rowSize)
{

}

int main()
{
    /*
        将多维数组传递给函数时，真正传递的是指向数组首元素的指针。因为我们处理的是数组的数组，所以首元素本身就是一个数组。
        指针就是一个指向数组的指针。数组的第二维的大小都是数组类型的一部分，不能省略
    */



    return 0;
}
