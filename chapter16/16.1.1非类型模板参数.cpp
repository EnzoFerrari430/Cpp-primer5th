#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
一个非类型参数表示一个值而非一个类型。
我们通过一个特定的类型名而非关键字class或typename来指定非类型参数
*/

template <unsigned N,unsigned M>
int compare(const char (&p1)[N],const char (&p2)[M])
{
    return strcmp(p1,p2);
}

int main()
{
    compare("hi","mom");



    return 0;
}
