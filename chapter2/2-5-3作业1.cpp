#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int a = 3,b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    decltype(a) e = a;
    decltype(a = b) f = a;  //赋值会产生引用 i = x的类型是int &
    //e是int型 f是const int型
    cout<<c<<" "<<d<<endl;
    cout<<e<<" "<<f<<endl;
    cout<<typeid(e).name()<<" "<<typeid(f).name()<<endl;

    return 0;
}
