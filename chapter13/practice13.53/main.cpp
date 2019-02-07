#include <iostream>
#include "HasPtr.h"
using namespace std;

/*
    进行拷贝赋值时，先通过拷贝构造创建了hp2的拷贝rhs，然后再交换hp和rhs，rhs作为一个中间媒介，只起到将值从hp2传递给hp的作用，是一个冗余的操作
    类似的在进行移动赋值时，先从hp2转移到rhs，再交换到hp也是冗余的操作。
    这种方式在实现上统一了拷贝和移动赋值运算，但是在性能角度多了一次rhs的间接传递，性能不好
*/

int main()
{
    HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
    hp1 = hp2;
    hp1 = std::move(hp2);



    cout << "Hello world!" << endl;
    return 0;
}
