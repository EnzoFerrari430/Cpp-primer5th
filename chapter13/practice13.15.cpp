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
int numbered::No = 0;  //��̬��Ա����Ҫ��������ж���ͳ�ʼ��

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
    //�ϳɵĿ��������,�Ҳ����ķǾ�̬��Ա��������������Ķ�Ӧ��Ա
    //�ȶ���a��a.mysn = 0;
    f(a);
    f(b);
    f(c);

    return 0;
}
