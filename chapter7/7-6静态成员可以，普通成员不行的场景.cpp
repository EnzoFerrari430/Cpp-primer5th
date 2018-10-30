#include <iostream>
#include <string>
using namespace std;
//静态成员独立于任何对象
//所以静态数据成员可以是不完全类型，而非静态数据成员则受到限制，只能声明成它所属类的指针或者引用

class Bar
{
public:
    //
private:
    static Bar men1;
    Bar *men2;
    //Bar men3;  //error men3的类型是不完全的
};

//另外的一个区别，静态成员可以作为默认实参
class Screen
{
public:
    //bkground表示一个在类中稍后定义的静态成员
    Screen &clear(char = bkground);
private:
    static const char bkground;
};
//非静态数据成员不能作为默认实参，因为它的值本身属于对象的一部分，这么做的结果是无法真正提供一个对象以便从中获取成员的值，最终将引发错误


int main()
{


    return 0;
}
