#include <iostream>
using namespace std;
/*
    ������������ת�����������Ŀ����ƶ���������һ��������Ķ���
    ������Щ���������麯�������Ե����Ǹ�����Ĺ��캯������һ�����������ʱ��ʵ�����еĹ��캯���ǻ����ж�����Ǹ�
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

int main()
{
    C c(1,2,3);
    A a1(c);  //���캯��ֻ�ܴ�������Լ��ĳ�Ա,�����Ե���c�еĳ�Աb��c
    A a2 = c;  //��ֵ�����ͬ��ֻ�ܴ�������Լ��ĳ�Ա�������Ե���c�еĳ�Աb��c
    cout<<a1.a<<endl;
    cout<<a2.a<<endl;

    return 0;
}
