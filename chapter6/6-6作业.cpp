#include <iostream>
using namespace std;

void f()
{
    cout<<"nothing"<<endl;
}
void f(int a1)
{
    cout<<"int"<<endl;
}
void f(int a1,int a2)
{
    cout<<"2int"<<endl;
}
void f(double a1,double a2 = 3.14)
{
    cout<<"2double"<<endl;
}

//6.53
int clac(int &a1,int &a2)
{
    cout<<"int&"<<endl;
}

int clac(const int &a1,const int &a2)
{
    cout<<"const int&"<<endl;
}

int clac(char *a1,char *a2)
{
    cout<<"char*"<<endl;
}
int clac(const char *a1,const char *a2)
{
    cout<<"const char*"<<endl;
}
int clac(char *const a1,char *const a2)  //���Ƕ���const,ָ�뱾����һ������
{
    cout<<"char *const"<<endl;
}
int main()
{
    //6.49 ��ѡ�����Ǻ�����һ�£������ڵ��õ����
    //���к����� �β������뱾�ε����ṩ��ʵ��������ȣ�ÿ��ʵ�ε��������Ӧ���β�������ͬ,������ת�����β�����

    //6.50
    //f(2.56,42);  ������
    f(42);
    f(42,0);  //f3 f4�����У�f3�����ƥ��
    f(2.56,3.14);  //f3 f4�����У�f4�����ƥ��




    return 0;
}
