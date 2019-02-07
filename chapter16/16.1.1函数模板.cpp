#include <iostream>
#include <string>
using namespace std;

//写一个函数来比较两个值,每个函数比较一种给定类型的值
//我们可能会定义多个重载函数
/*
int compare(const string &v1,const string &v2)
{
    if(v1 < v2)
        return -1;
    if(v2 > v1)
        return 1;
    return 0;
}

int compare(const int &v1,const int &v2)
{
    if(v1 < v2)
        return -1;
    if(v1 > v2)
        return 1;
    return 0;
}
*/

/*
函数的唯一差异是参数的类型，函数体则完全一样

我们可以用一个函数模板，而不是为每个类型都定义一个新函数

函数模板就是一个公式，可以用来生成针对特定类型的函数版本
*/

//可以写成下面的模板形式
template <typename T>
int compare(const T &v1,const T &v2)
{
    if(v1 < v2)
        return -1;
    if(v1 > v2)
        return 1;
    return 0;
}
/*
模板的定义以关键字template开始，后面跟一个模板参数列表
*/

/*
compare函数有一个模板 类型参数。可以将它作为类型说明符，就像内置类型或类类型说明符一样使用。
类型参数可以用来指定返回类型或函数的参数类型
*/
template <typename T> T foo(T* p)
{
    T tmp = *p;

    return tmp;
}

int main()
{

    cout<<compare(3,0)<<endl;
    cout<<compare("hello","world")<<endl;


    return 0;
}
