#include <iostream>
using namespace std;
//void f(int &a[10]);  ����д���Ǵ�ģ��������͵������ǷǷ��ġ� ��Ϊ��������ָ�����õ�ָ�����������ǿ��ת����ָ�롣
int bigger(int n,const int *p)
{
    if(n>*p)
        return n;
    else
        return *p;
}
int main()
{
    int i = 30;
    int p = 40;
    cout<<bigger(i,&p)<<endl;



    return 0;
}
