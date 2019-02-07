#include <iostream>
using namespace std;
/*
    ���յ������ཫ��������ֱ�ӻ�����Ӷ����Լ�ÿ����ӻ�����Ӷ���

*/

class A
{
public:
    A(int aa = 0):a(aa){}
public:
    int a;
};

class B :public A
{
public:
    B(int aa = 0,int bb = 0):A(aa),b(bb){}
public :
    int b;
};

class C : public B
{
public:
    C(int aa = 0,int bb = 0,int cc = 0):B(aa,bb),c(cc){}
public:
    int c;
};

/*
    C++11�������ṩһ�ַ�ֹ�̳з����ķ���
    �������������һ���ؼ���final
*/

class NoDerived final  //  NoDerived������Ϊ����
{

};

class Base
{

};

class Last final : Base  //Last������Ϊ����
{

};

class Bad : NoDerived  //����NoDerived��final
{

};

class Bad2:Last  //���� Last��final��
{

};

int main()
{
    C c(1,2,3);
    cout<<c.a<<" "<<c.b<<" "<<c.c<<endl;
    cout<<sizeof(A)<<endl;  //4
    cout<<sizeof(B)<<endl;  //8
    cout<<sizeof(C)<<endl;  //12  ���յ������ཫ��������ֱ�ӻ�����Ӷ����Լ�ÿ����ӻ�����Ӷ���

    return 0;
}
