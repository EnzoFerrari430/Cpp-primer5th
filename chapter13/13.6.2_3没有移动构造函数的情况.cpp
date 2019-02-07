#incldue <iostream>
using namespace std;


/*
    如果类定义了拷贝构造函数但是未定义移动构造函数。
    ！！！！在此情况下，编译器不会合成移动构造函数。
    但是在函数匹配规则下保证该类型的对象会被拷贝，即使我们试图通过move来移动它们
*/

class Foo
{
public:
    Foo() = default;
    Foo( const Foo& );  //拷贝构造函数
    //其他成员定义，但是Foo未定义移动构造函数
};


int main()
{
    Foo x;
    Foo y(x);  //拷贝构造函数； x是一个左值
    Foo z(std::move(x));  //拷贝构造函数，因为未定义移动构造函数
    //在对z进行初始化时，调用了move(x)，它返回一个绑定到x的Foo&&  Foo的拷贝构造函数是可行的，因为可以将一个Foo&&转换为一个const Foo&  因此z的初始化将使用Foo的拷贝构造函数

    return 0;
}
