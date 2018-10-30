#include <iostream>
using namespace std;
/*
成员函数中使用名字按照下面的方式解析：
    首先，在成员函数内查找该名字的解析。和前面一样，只有在函数使用之前出现的声明才被考虑
    如果在成员函数内没有找到，则在类内继续查找，这时类的所有成员都可以被考虑
    如果类内也没有找到该名字的声明，在成员函数定义之前的作用域中继续查找




    如果编译器在函数和类的作用域中都没有找到名字，它将接着在外围的作用域中查找。

    当成员定义在类的外部时，名字查找的第三部不仅要考虑类定义之前的全局作用域中的声明，还需要考虑在成员函数定义之前的全局作用域中的声明
*/

int height;  //定义了一个名字
class Screen
{
public:
    typedef std::string::size_type pos;
    void setHeight(pos);
    pos height = 0;  //隐藏了外层作用域中的height
};
Screen::pos verify(Screen::pos);

void Screen::setHeight(pos var)
{
    //var 参数
    //height 类的成员
    //verify 全局函数
    height = verify(var);
}

int main()
{




    return 0;
}
