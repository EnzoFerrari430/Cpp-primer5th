#include <iostream>
using namespace std;

class A
{
public:
    void print(){cout<<".a..a";}
    A(int f){n = f;cout<<"构造函数"<<endl;}
    int n;
};


int main()
{
    //A a;   ★当没有定义构造函数时，编译器会自动合成默认构造函数（而不是没有定义默认构造函数）
    //a.print();

    return 0;
}
