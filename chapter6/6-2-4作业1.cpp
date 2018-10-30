#include <iostream>
using namespace std;
//void f(int &a[10]);  这种写法是错的，引用类型的数组是非法的。 因为不允许有指向引用的指针和数组名被强制转换成指针。
int bigger(int n,const int *p)
{
    if(n>*p)
        return n;
    else
        return *p;
}
int main()
{
    int i = 30;
    int p = 40;
    cout<<bigger(i,&p)<<endl;



    return 0;
}
