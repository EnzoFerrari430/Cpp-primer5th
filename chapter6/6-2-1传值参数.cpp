#include <iostream>
using namespace std;
/*
    当初始化一个非引用类型的变量时，初始值被拷贝给变量。此时，对变量的改动不会影响初始值
    传值参数的机理完全一致，函数对形参做的所有操作都不会影响实参。


    指针的行为和其他非引用类型一样。当执行指针拷贝操作时，拷贝的是指针的值
*/
int minuss(int n)
{
    return --n;
}

void reset(int *p)
{
    *p = 0;  //改变指针p所指对象的值
    p = 0;   //只改变p的局部拷贝，实参不变
}

int main()
{
    int n = 0;
    int i = n;
    i = 42;
    cout<<n<<endl;

    int data = 8;
    cout<<minuss(data)<<endl;  //minuss函数改变了data的值，但是这个改动不会影响传入minuss的实参
    cout<<data<<endl;

    cout<<&i<<endl;
    reset(&i);
    cout<<"i: "<<i<<endl;
    cout<<&i<<endl;  //实参的值不改变


    return 0;
}
