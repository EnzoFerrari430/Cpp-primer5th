/*
不可以，因为实例化vector<NoDefault>时，编译器会实例化vector的所有成员函数
包括它接受容器大小参数的构造函数。vector的这个构造函数会使用元素类型的默认构造函数来对元素进行值初始化。
而NoDefault没有默认构造函数，会导致编译错误,可以试验一下
*/

#include <iostream>
#include <vector>

using namespace std;

class NoDefault
{
public:
    //NoDefault():a(0){}  没有该默认构造函数就会报错
    NoDefault(int z):a(z){}
private:
    int a;
};

template class vector<NoDefault>;

int main()
{


    return 0;
}
