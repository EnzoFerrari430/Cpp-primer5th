#include <iostream>
using namespace std;

void ff(int)
{
    cout<<"int"<<endl;
}
void ff(short)
{
    cout<<"short"<<endl;
}

void manip(long)
{
    cout<<"long"<<endl;
}
void manip(float)
{
    cout<<"float"<<endl;
}
int main()
{
    /*
        实参类型到形参类型的转换等级
        1.精确匹配，包括以下情况
            实参类型和形参类型相同
            实参从数组类型或函数类型转换成对应的指针类型
            向实参添加顶层const或者从实参中删除顶层const
        2.通过const转换实现的匹配
        3.通过类型提升实现的匹配(从比较的整数类型提升到较大的整数类型: bool 提升到 int)
        4.通过算术类型转换(表达式中既有浮点类型又有整数类型，整数转换成浮点类型)或指针转换实现匹配(0和nullptr可以转换成任意指针类型)
        5.通过类类型转换实现匹配(后面再讲)

    */
    short f = 1;
    ff('a');  //char 提升成int,只有当调用提供short类型的值时，才调用short
    ff(f);
    //所有算术类型转换的级别都一样

    //manip(3.14);  二义性  字面值3.14的类型是double型，它既可以转换成float型也可以转换成long类型，所以该调用存在二义性

    return 0;
}
