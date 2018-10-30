#include <iostream>
using namespace std;
/*
    如果重载函数的区别在于它们的引用类型的形参是否引用了const，或者指针类型的形参是否指向const，
    则当调用发生时编译器通过实参是否是常量来决定选择哪个函数

    指针类型的形参也类似。如果2个函数的唯一区别是它的指针形参指向常量或非常量，则编译器能通过实参是否是常量决定选用哪个函数
*/

void lookup(int &m)
{
    cout<<"普通引用"<<endl;
}

void lookup(const int &m)
{
    cout<<"常量引用"<<endl;
}

int main()
{
    const int a = 4;
    int b;
    lookup(a);  //常量引用,不能把普通引用绑定到const对象上
    lookup(b);  //普通引用,2个函数都是可行,非常量形参的版本与b精确匹配,所以这里选用的是非常量版本


    return 0;
}
