#include <iostream>
using namespace std;
/*
    ����ʼ��һ�����������͵ı���ʱ����ʼֵ����������������ʱ���Ա����ĸĶ�����Ӱ���ʼֵ
    ��ֵ�����Ļ�����ȫһ�£��������β��������в���������Ӱ��ʵ�Ρ�


    ָ�����Ϊ����������������һ������ִ��ָ�뿽������ʱ����������ָ���ֵ
*/
int minuss(int n)
{
    return --n;
}

void reset(int *p)
{
    *p = 0;  //�ı�ָ��p��ָ�����ֵ
    p = 0;   //ֻ�ı�p�ľֲ�������ʵ�β���
}

int main()
{
    int n = 0;
    int i = n;
    i = 42;
    cout<<n<<endl;

    int data = 8;
    cout<<minuss(data)<<endl;  //minuss�����ı���data��ֵ����������Ķ�����Ӱ�촫��minuss��ʵ��
    cout<<data<<endl;

    cout<<&i<<endl;
    reset(&i);
    cout<<"i: "<<i<<endl;
    cout<<&i<<endl;  //ʵ�ε�ֵ���ı�


    return 0;
}
