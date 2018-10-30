#include <iostream>
using namespace std;


//操作系统还没有立刻将本地变量的内存分配给其他变量，但这是暂时的、不稳定的。
int &add()
{
    int a,b;
    a = 4;
    b = 5;
    int c = a + b;
    int &d = c;
    return d;


}

int main()
{
    cout<<add()<<endl;

    return 0;
}
