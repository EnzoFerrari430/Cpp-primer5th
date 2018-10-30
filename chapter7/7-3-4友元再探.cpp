#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen;

class Window_mgr
{
public:


    //窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    //根据编号将指定的Screen重置为空白
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &);

private:
    vector<Screen> screens;  //这个Screen类还没有定义好 ，所以不能初始化
};



class Screen
{

    //friend class Window_mgr;
    //也可以只为clear函数提供访问权限
    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type pos;
    Screen() = default;  //因为Screen有另一个构造函数，所以本函数是必须的
    //cursor被其类被初始化为0

    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c) {} //cursor成员隐式的使用了类内初始值
    char get() const
    {
        return contents[cursor];   //隐式内联
    }
    inline char get(pos ht,pos wd) const;  //显式内联
    Screen &move(pos r,pos c);  //能在之后被设为内联
    void some_member() const;
    pos size() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    //mutable关键字  可变数据成员，永远不会是const，即使是const对象的成员
    mutable size_t access_ctr;  //在const对象内也能被修改
};

//移动光标
inline
Screen &Screen::move(pos r,pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;  //以左值的形式返回对象
}

//读取给定位置的字符
char Screen::get(pos r,pos c) const  //在内部声明成inline
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const  //这里的const表示this是一个指向常量的指针
{
    ++access_ctr;  //保存一个值，用于记录成员函数被调用的次数
}


//pos在类名之前，需要作用域访问符
Screen::pos Screen::size() const
{
    return height * width;
}

void Window_mgr::clear(ScreenIndex i)
{
    //s是一个Screen的引用，指定我们想清空的那个屏幕
    Screen &s = screens[i];

    s.contents = string(s.height * s.width, ' ');
}

/*
declare class does not name a type

出现这个编译错误主要有四个可能原因，现总结如下：

1.引用的类命名空间未包含

2.引用的类头文件未包含

3.包含了头文件，或者已经前置声明了，则说明所引用的类名写错。

4.循环引用头文件
*/

//返回类型出现在类名之前，想使用ScreenIndex作为返回类型，就要明确指定哪个类使用了它
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}




int main()
{
    Screen::pos ht = 24;

    return 0;
}
