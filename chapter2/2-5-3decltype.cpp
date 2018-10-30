#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    /*
        C++11引入第二种类型说明符decltype，它的作用是选择并返回操作数的数据类型。
        在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值

    */
    //int num = 42;
    //int &r = num;
    const int ci = 0,&cj = ci;
    //decltype(num) x;
    decltype(ci) y = ci;  //const和引用必须初始化
    //cout<<typeid(x).name()<<endl;
    //如果decltype的表达式不是一个变量，则decltype返回表达式结果对应的类型
    int i = 42,*p = &i,&r = i;
    decltype(r) a = r;
    decltype(r + 0) b;  //b 是一个未初始化的int型变量
    //如果表达式内容是解引用操作，则decltype将得到引用类型
    //decltype(*p) c = r;  //c是int & 必须初始化
    /*
        decltype和auto的区别
        decltype的结果类型和表达式密切相关。

        注意：decltype所用的表达式，如果变量名加上了括号。则得到的类型与不加括号的有可能会不一样

    */
    //decltype((i)) d; // 2层括号的结果永远是引用
    decltype(i) e;

    return 0;
}
