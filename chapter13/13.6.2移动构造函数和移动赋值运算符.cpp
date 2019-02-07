#include <iostream>
using namespace std;


//当一个类没有定义任何自己版本的拷贝控制成员，且类的每个非static数据成员都可以移动时，编译器才会为它合成移动构造函数或移动赋值运算符。
//编译器可以移动内置类型的成员，类类型如果有对应的移动操作，编译器也能移动这个成员
class X
{
public:
    int i;              //内置类型可以移动
    std::string s;      //string定义了自己的移动操作
};

class hasX
{
public:

    X mem;
};

//假定Y定义了自己的拷贝构造函数但未定义自己的移动构造函数
class Y
{
public:
    Y():i(0){};
    Y(const Y &rhs){i = rhs.i;}
    //Y( Y && ) = delete;
    int i;
    const int p = 10;
};

class hasY
{
public:

    hasY() = default;
    hasY( hasY && ) = default;
    Y mem;  //有类成员定义了自己的拷贝构造函数且未定义移动构造函数，则移动构造函数被定义为删除的
};

int main()
{
    X x,x2 = std::move(x);
    hasY hy,hy2 = std::move(hy);  //如果Y的移动构造函数定义为删除的，则这里显式调用会失败
    return 0;
}
