#include <iostream>
using namespace std;
int power3(int n)
{
    int num = 1;
    int i ;
    for(i = 0 ;i<3;i++)
    {
        num *= n;
    }
    return num;
}
int main()
{
    /*
        6.1�βξ��Ǻ����ڶ����ʱ����ʽ�ϵĲ��������ڸ����������������Ҫ�Ĳ���
           ʵ�ξ������ú�����ʱ��Ҫʵ��ʹ�õĲ���

        6.2a �����ķ������Ͳ�һ��
        6.2b ����û�з�������
        6.2c �����ββ�������
        6.2d �����ĺ����������"{}"������
    */

    //6.3
    cout<<power3(10)<<endl;

    return 0;
}
