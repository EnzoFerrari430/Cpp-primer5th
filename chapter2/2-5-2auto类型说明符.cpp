#include <iostream>
#include <typeinfo>
using namespace std;

/*
C++11新标准引入说明符，它能让编译器替我们去分析表达式所属的类型。auto让编译器通过初始值来推算变量的类型
所以auto定义的变量是一定要初始值的


*/
int main()
{
    //auto i = 0,*p = &i;  //正确，i是整数，p是整型指针
    //auto sz = 0,pi = 3.14;  //错误，sz和pi的类型不一样

    //复合类型 常量和 auto
    //引用其实是使用引用的对象，当引用被用作初始化时，auto根据引用对象的类型来确定auto的类型
    int i = 0 ,&r = i;
    auto a = r;
    //cout<<typeid(a).name()<<endl;  //a的类型是int

    //auto会忽略掉顶层const 底层const会保留下来
    const int ci = i,&cr = ci;
    auto b = ci;  //b是int型
    auto c = cr;  //c是int型
    auto d = &i;  //d是一个整型指针(整数的地址就是指向整数的指针) pi
    auto e = &ci; //e是一个指向整数常量的指针(对常量对象取地址是一种底层const) pki
    cout<<typeid(e).name()<<endl;
    cout<<typeid(&ci).name()<<endl;

    //如果希望推断出一个顶层const，就需要明确指出
    const auto f = ci;  //ci推演类型是int，f是const int
    auto &g = ci;  //g的类型是int
    cout<<typeid(g).name()<<endl;
    //auto &h = 42; 不能用非常量引用来绑定字面值
    const auto &j = 42;  //可以为常量引用绑定字面值
    cout<<typeid(j).name()<<endl;

    a = 42;
    b = 42;
    c = 42;
    //d = 42;
    //e = 42;
    //g = 42; const int

    cout<<a<<" "<<b<<" "<<c<<endl;


    return 0;
}
