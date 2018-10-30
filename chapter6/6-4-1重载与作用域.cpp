#include <iostream>
using namespace std;
/*
    重载对作用域的一般性质并没有发生什么改变。如果我们在内层作用域中声明名字，它将隐藏外层作用域中声明的同名实体。
    在不同的作用域中无法重载函数名

    ★C++语言中，名字查找发生在类型检查之前
*/
string read();
void print(const string &);
void print(double);  //重载print函数

void foolBar(int ival)
{
    bool read = false;  //新作用域:隐藏了外层的read
    string s = read();  //错误:read是一个布尔值，而非函数

    //不好的习惯，通常来说，在局部作用域中声明函数不是一个好的选择
    void print(int);    //新的作用域，隐藏了之前的print

    print("value: ");   //错误:print(const string &)被隐藏掉了
    print(ival);        //正确:当前print(int)可见
    print(3.14);        //正确，调用的是print(int), print(double)被隐藏掉了
}

int main()
{


    return 0;
}
