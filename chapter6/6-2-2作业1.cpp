#include <iostream>
using namespace std;
void SwapData(int &i1,int &i2)
{
    int temp;
    temp = i1;
    i1 = i2;
    i2 = temp;
}
int main()
{
    int a1 = 30;
    int a2 = 15;
    SwapData(a1,a2);
    cout<<a1<<' '<<a2<<endl;

    /*
        6.13
        void f(T) 函数对T的操作不会影响实参
        void f(&T) T和实参绑定起来，操作实参
        6.14
        如果需要修改实参，就可以用引用
        6.15
        string 对象的长度可能会非常长，要避免直接拷贝他们，而且string对象无需改变，所以用const
        occurs需要用来记录字符c出现的字符，会发生改变，所以是普通引用
        c只是一个临时变量，不用修改。
    */

    return 0;
}
