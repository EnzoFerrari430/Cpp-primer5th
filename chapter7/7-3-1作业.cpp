#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen
{
public:
    using pos = string::size_type;  //string的单位类型
    Screen() = default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht * wd,' '){}
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c) {}
    char get() const
    {
        return contents[cursor];   //隐式内联
    }
    inline char get(pos ht,pos wd) const;  //显式内联
    Screen &move(pos r,pos c);  //能在之后被设为内联
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

//7.25  内置类型和string类型可以拷贝和赋值操作

int main()
{


    return 0;
}
