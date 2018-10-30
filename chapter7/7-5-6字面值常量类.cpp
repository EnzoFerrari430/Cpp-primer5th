#include <iostream>
using namespace std;
/*
    数据成员都是字面值类型的聚合类是字面值常量类

    如果不是聚合类但是满足下面条件也是字面值常量类
        1.数据成员都必须是字面值类型
        2.类必须至少含有一个constexpr构造函数
        3.如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式；
            或者如果成员属于某种类类型，则初始值必须使用成员自己的constexpr构造函数
        4.类必须使用析构函数的默认定义，该成员负责销毁类的对象

    尽管构造函数不能是const，但是字面值常量类的构造函数可以是constexpr函数。in fact一个字面值常量类必须至少提供给一个constexpr构造函数

    constexpr函数要求 它能拥有唯一可执行语句就是返回语句，但是构造函数就允许有返回语句。
    所以constexpr构造函数一般就是空的函数体

    constexpr构造函数必须初始化所有数据成员，初始值或者使用constexpr构造函数，或者是一条常量表达式

    constexpr构造函数用于生成constexpr对象以及constexpr函数的参数或者返回类型：
*/
class Debug
{
public:
    constexpr Debug(bool b = true):hw(b),io(b),other(b){}
    constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}
    constexpr bool any() {return hw || io || other;}

    void set_io(bool b){io = b;}
    void set_hw(bool b){hw = b;}
    void set_other(bool b){hw = b;}
private:
    bool hw;
    bool io;
    bool other;
};



int main()
{
    return 0;
}
