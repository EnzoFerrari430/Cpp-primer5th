#include <iostream>
#include <string>
using namespace std;
//C++不允许使用为初始化的变量，而初始化操作和定义变量对于变量来说是两码事，
//★初始化操作是在运行时才会被调用的语句，是可以被case跳转屏蔽掉的语句，而定义是在编译时就完成的检查的
int main()
{
    //不合理的写法
    int idx = 2;
    switch(idx)
    {
        string str; //string是一个类，这个类有自己的隐式初始化， 所以这也是一个初始化语句,也有可能被跳过
        int k = 1;  //这是一个初始化语句         跳过了变量的初始化
    case 1:
        int j = 1;  //这也是一个初始化语句
        break;
    case 2:
        k = 1;
        j = 2;
        cout<<"k: "<<k<<endl;
        cout<<"j: "<<j<<endl;
        break;
    default:
        break;
    }



    return 0;
}
