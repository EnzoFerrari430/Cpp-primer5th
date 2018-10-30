#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NoDefault
{
public:
    NoDefault(int a):data(a){}
    int data;
};

class C
{
public:
    NoDefault nd;
    C():nd(0){}
};

int main()
{
    C c;
    cout<<c.nd.data;
    //vector<NoDefault> vec(10);  NoDefault没有默认构造函数，不能初始化
    vector<C> vec(10);  //因为C有默认构造函数 所以OK
    return 0;
}

//7.46
//a. 错  不提供构造函数，编译器会自己合成一个默认构造函数
//b. 错  为成员提供默认值的构造函数 也是默认构造函数
//c. 错  类应该提供默认构造函数
//d. 错  只有没有定义构造函数时，编译器才会生成默认构造函数

