#include <iostream>
using namespace std;
//变量的有没有被定义是在编译时就检查过的,这里编译可以通过
//在处理switch case 语句中，C++11标准的编译器都会在执行case跳转前为变量分配空间，因此执行也没有问题
int main()
{
    int idx = 2;
    switch(idx)
    {
        int k;
    case 1:
        int j;
        break;
    case 2:
        k = 1;
        j = 2;
        cout<<"K: "<<k<<endl;
        cout<<"J: "<<j<<endl;
        break;
    default:
        break;
    }
    return 0;
}
