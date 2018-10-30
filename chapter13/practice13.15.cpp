#include <iostream>
#include <string>
#include <vector>
using namespace std;


class numbered
{
public:
    numbered();
    numbered(const numbered &);
public:
    static int No;
    int mysn;

};
int numbered::No = 0;  //静态成员变量要在类外进行定义和初始化

numbered::numbered()
{
    mysn = No;
    ++No;
}

numbered::numbered(const numbered &rhs)
{
    mysn = No;
    ++No;
}

void f( numbered s )
{
    cout<<s.mysn<<endl;
}

int main()
{
    numbered a,b = a,c = b;
    //合成的拷贝运算符,右侧对象的非静态成员赋予左侧运算对象的对应成员
    //先定义a，a.mysn = 0;
    f(a);
    f(b);
    f(c);

    return 0;
}
