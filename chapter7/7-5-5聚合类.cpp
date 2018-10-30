#include <iostream>
#include <string>
using namespace std;
/*
    聚合类使得用户可以直接访问其成员，并且具有特殊的初始化语法形式。当一个类满足如下条件，我们说它是聚合类：
        1.所有成员都是public的
        2.没有定义任何构造函数
        3.没有类内初始值
        4.没有基类，也没有virtual函数
*/
//一个聚合类
struct Data
{
    int ival;
    string s;
    string book;
    int p;
};
int main()
{
    //★初始化顺序必须与声明的顺序一致
    //如果初始值列表中的元素个数少于类的成员数量，则靠后的成员被值初始化。★初始值列表的元素个数绝对不能超过类的成员数量
    Data vall = {0,"Anna"};
    cout<<vall.p;
    return 0;
}
