#include <iostream>
using namespace std;
void SwapData(int *p1,int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;  //指针形参。 指针所指对象的值发生改变，但是实参本身没有改变
    *p2 = temp;
}

void SwapInt(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a1,a2;
    a1 = 42;
    a2 = 21;
    cout<<&a1<<' '<<&a2<<endl;
    SwapData(&a1,&a2);
    cout<<&a1<<' '<<&a2<<endl;  //指针形参。 指针所指对象的值发生改变，但是实参本身没有改变
    cout<<a1<<' '<<a2<<endl;

    SwapInt(a1,a2);  //★函数对形参做的所有操作都不会影响实参
    cout<<a1<<' '<<a2<<endl;

    return 0;
}
