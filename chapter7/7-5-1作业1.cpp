#include <iostream>
using namespace std;

struct X
{
    //�����һ����Ա����ʼ����һ����Ա����Ҫ���Ƕ����Աʱ��˳��,�ȶ���rem���Ի��ȳ�ʼ��rem,Ҫ��rem�ź���
    X(int i,int j):base(i),rem(base % j){}
    int base,rem;
};

int main()
{
    X x(4,2);
    cout<<x.rem<<' '<<x.base;

    return 0;
}
