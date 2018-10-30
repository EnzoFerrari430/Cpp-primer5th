#include <iostream>
using namespace std;

struct X
{
    //如果用一个成员来初始化另一个成员，就要考虑定义成员时的顺序,先定义rem所以会先初始化rem,要把rem放后面
    X(int i,int j):base(i),rem(base % j){}
    int base,rem;
};

int main()
{
    X x(4,2);
    cout<<x.rem<<' '<<x.base;

    return 0;
}
