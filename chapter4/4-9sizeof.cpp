#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i = 10;
    int &r = i;
    cout<<sizeof(r)<<endl;
    cout<<sizeof("hello world")<<endl;

    double pi = 3.14;
    double &dr = pi;
    cout<<sizeof(dr)<<endl;
    int *p = &i;
    int *p2;
    cout<<sizeof(p)<<endl;  //指针本身所占空间的大小
    cout<<sizeof(*p2)<<endl;  //得到指针指向的对象所占空间大小,指针不需要有效

    int a[10];
    cout<<sizeof(a)<<endl;  //得到整个数组所占空间的大小,等价于数组中所有元素各执行一次sizeof运算并将所得结果求和

    string str;
    cout<<sizeof(str)<<endl;  //string或者vector对象执行sizeof运算只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间
    return 0;
}
