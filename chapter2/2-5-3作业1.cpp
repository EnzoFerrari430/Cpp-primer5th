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
    decltype(a = b) f = a;  //��ֵ��������� i = x��������int &
    //e��int�� f��const int��
    cout<<c<<" "<<d<<endl;
    cout<<e<<" "<<f<<endl;
    cout<<typeid(e).name()<<" "<<typeid(f).name()<<endl;

    return 0;
}
