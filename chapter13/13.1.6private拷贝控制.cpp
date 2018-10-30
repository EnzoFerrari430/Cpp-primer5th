#include <iostream>
using namespace std;



/*
    在新标准发布之前，类是通过将其拷贝构造函数和拷贝赋值运算符声明为private的来阻止拷贝

*/

class PrivateCopy
{
    //无访问说明符：接下来的成员默认是private的
    //拷贝控制成员是private的，因此普通用户代码无法访问
    //但是友元和成员函数仍旧可以拷贝对象。为了阻止友元和成员函数进行拷贝，我们将这些拷贝控制成员声明为private的，！！但是不定义它们
    PrivateCopy(const PrivateCopy&);
    PrivateCopy &operator=(const PrivateCopy&);

public:
    PrivateCopy() = default;  //使用合成的默认构造函数
    ~PrivateCopy();  //用户可以定义此类型对象，但无法拷贝它们
};

int main()
{


    return 0;
}
