#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i = 10;
    int &r = i;
    cout<<sizeof(r)<<endl;
    cout<<sizeof("hello world")<<endl;

    double pi = 3.14;
    double &dr = pi;
    cout<<sizeof(dr)<<endl;
    int *p = &i;
    int *p2;
    cout<<sizeof(p)<<endl;  //ָ�뱾����ռ�ռ�Ĵ�С
    cout<<sizeof(*p2)<<endl;  //�õ�ָ��ָ��Ķ�����ռ�ռ��С,ָ�벻��Ҫ��Ч

    int a[10];
    cout<<sizeof(a)<<endl;  //�õ�����������ռ�ռ�Ĵ�С,�ȼ�������������Ԫ�ظ�ִ��һ��sizeof���㲢�����ý�����

    string str;
    cout<<sizeof(str)<<endl;  //string����vector����ִ��sizeof����ֻ���ظ����͹̶����ֵĴ�С�������������е�Ԫ��ռ���˶��ٿռ�
    return 0;
}
