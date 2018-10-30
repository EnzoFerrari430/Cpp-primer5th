#include <iostream>
#include <fstream>
using namespace std;
int main()
{

    ofstream out1,out2;
    //out1 = out2;  //error 不能对流对象赋值
    //ofstream print(ofstream);  //error 不能初始化ofstream参数  这里被当成了函数的声明
    //out2 = print(out2);  //不能拷贝流对象
    //进行IO操作的函数通常以引用方式传递和返回流。读写一个IO对象会改变其状态，因此传递和返回的引用不能是const

    return 0;
}
