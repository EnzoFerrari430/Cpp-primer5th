#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

template<class T>

void printtemp(T a)
{
    cout<<typeid(a).name()<<endl;
}
int main()
{
    /*
        命名的强制类型转换
            cast-name<type>(expression);
            type:转换目标
            expression:要转换的值
            cast-name:
                static_cast(不包含底层const都可以  指针指向的对象是常量)
                dynamic_cast
                const_cast
                reinterpret_cast

    ★强制类型转换说明程序存在某种设计缺陷，要避免使用
    */
    double pi = 3.1415;
    int i = pi;

    const int j = 10;

    //void* 可以存放任意类型的指针  任何非常量对象的地址都能存入void*
    void *p = &i;

    //cout<<*p<<endl;  void* 能接收任何类型的指针，对它解引没有意义
    printtemp(i);
    printtemp(pi);
    printtemp(p);
    printtemp(static_cast<int>(pi));  //临时转换，不改变本身类型
    printtemp(pi);
    double *dp = static_cast<double*>(p);  //就只是在这里强转一下,本身还是Pv
    printtemp(p);

    //const char *c;
    //char *const d;  这个定义的时候就一定要初始化

    const char *cp;
    //char *q = static_cast<char*>(cp);  static_cast不能转换掉const性质
    static_cast<string>(cp);  //字符串字面值转换成string类型
    return 0;
}
