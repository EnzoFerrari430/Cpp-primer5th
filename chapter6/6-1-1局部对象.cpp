#include <iostream>
using namespace std;
size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}
int main()
{
    /*
        对于普通局部变量对应的对象来说，当函数的控制路径经过变量定义语句时创建该对象，当到达定义所在的块末尾时销毁它。
        我们把只存在于块执行期间的对象称为自动对象


        ★局部静态对象: 有些时候需要让局部变量的声明周期贯穿函数调用及之后的时间.可以将局部变量定义成static类型从而获得这样的对象。
    局部静态对象在程序执行路径第一次经过对象定义语句的时候初始化，并且到程序终止才被销毁，在此期间即使对象所在的函数结束执行也不会对它有影响
    */

    for(size_t i = 0; i != 10; ++i)
    {
        cout<<count_calls()<<endl;
    }


    return 0;
}
