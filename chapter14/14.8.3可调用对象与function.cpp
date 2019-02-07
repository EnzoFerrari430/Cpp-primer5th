#include <iostream>
#include <string>
using namespace std;
/*
    什么是可调用对象：就是在该对象后面能加调用运算符的()
    C++语言中有几种可调用对象：函数、函数指针、lambda表达式、bind创建的对象以及重载了函数调用运算符的类

    然而，两个不同类型的可调用对象却可能共享同一种调用形式。
    调用形式指明了调用 “返回的类型” 以及传递给 “调用的实参类型” 。

    int(int ,int)  这是一个函数类型，它接受两个int、返回一个int

*/

//不同类型可能具有相同的调用形式
//普通函数
int add(int i,int j){return i+j;}
//lambda,其产生一个未命名的函数对象类
auto mod = [](int i,int j){return i % j;};
//函数对象类
struct divide
{
    int operator()(int denominator,int divisor){
        return denominator / divisor;
    }
};
int main()
{


    return 0;
}
