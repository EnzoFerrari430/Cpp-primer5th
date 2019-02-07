#include <iostream>
using namespace std;


struct A
{
public:
    void operator()(){cout<<"hellow orld"<<endl;}
};

int main()
{


    A()();  //A()  构造了一个临时对象，然后再调用 函数调用运算符
    return 0;
}
