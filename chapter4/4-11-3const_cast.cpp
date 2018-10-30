#include <iostream>
using namespace std;
int main()
{

    int const i = 10;
    const int *p = &i;
    //int modifier = i;  编译通过，但是没有意义

    //int *modifier = &i;  不能将const int *转换成int *   但是C语言中可以实现

    //int &modifier = i;  不能用const int 初始化int &
    int *modifier = const_cast<int *>(p);  //去掉了const属性

    *modifier = 7;
    cout<< "i: "<<i<<endl;
    cout<< "p: "<<*p<<endl;
    cout<< "modifier: "<<*modifier<<endl;

    //地址
    cout<< "i: "<<&i<<endl;
    cout<< "p: "<<p<<endl;
    cout<< "modifier: "<<modifier<<endl;

    //地址不变，*modifier = 7;未定义行为（Undefined Behavior）对于未定义行为，我们所能做的所要做的就是避免出现这样的语句。

    //原因是，我们可能调用了一个参数不是const的函数，而我们要传进去的实际参数确实const的，但是我们知道这个函数是不会对参数做修改的。
    //于是我们就需要使用const_cast去除const限定，以便函数能够接受这个实际参数。
    return 0;
}
