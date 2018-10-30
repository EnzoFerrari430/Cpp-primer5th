#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

    //不要用get初始化另一个智能指针或为智能指针赋值
    //get函数，它返回一个内置指针，指向智能指针管理的对象

int main()
{
    shared_ptr<int> p(new int(321321));  //引用计数为1
    int *q = p.get();  //正确，但是不要让q管理的指针被释放
    {
        //未定义:两个独立的shared_ptr指向相同的内存
        shared_ptr<int>(q);
    }  //语句块结束，q被销毁，它指向的内存被释放
    int foo = *p;  //未定义:p指向的内存已经被释放
    cout<<foo<<endl;


    return 0;
}
