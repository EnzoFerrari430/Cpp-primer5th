#include <iostream>
#include <string>
using namespace std;
void reset(int *p)
{
    *p = 123;
    p = 0;
}
void Rreset(int &r)
{
    r = 456;
}
int main()
{
    /*
        前文：顶层const作用于对象本身

        当用实参初始化形参时，会忽略掉顶层const

        我们可以使用非常量初始化一个底层const对象，但是反过来不行
        一个普通的引用必须用同类型的对象初始化
    */
    /*
    int i = 42;
    const int &r = i;
    //r = 3;
    cout<<r<<endl;
    */
    /*
    int p1 = 32;
    int &rp = p1;
    p1 = 3;
    cout<<rp<<endl;
    */

    /*
    const int p1 = 32;
    int *pp = &p1;  //不能用指向const int 对象的指针初始化int *
    */

    int i = 0;
    const int ci = i;
    //&ci//指向const int对象的指针
    const int *p = &ci;
    string::size_type ctr = 0;

    reset(&i);  //正确
    //reset(&ci);
    //reset(p);  //不能用指向const int 对象的指针初始化int *
    //Rreset(ci);  //对普通引用无效的初始化，不能用const对象来初始化
    //Rreset(42);  //不能用字面值常量来初始化普通引用
    //Rreset(ctr); //2者类型不同 ctr是无符号型

    //要想调用int引用类型的函数，不能使用字面值、求值结果为int型的表达式、需要转换的对象或者const int类型的对象
    //要想调用int指针类型的函数，只能使用int *



    return 0;
}
