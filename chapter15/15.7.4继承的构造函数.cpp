#include <iostream>
using namespace std;
/*
    һ����ֻ�ܳ�ʼ������ֱ�ӻ��࣬����ͬ����ԭ��һ����Ҳֻ�ܼ̳���ֱ�ӻ���Ĺ��캯��

    ʹ�÷������ṩһ��ע����ֱ�ӻ�������using���

    ����using��������ڹ��캯��ʱ��using������佫���������������
*/

class Base
{
public:
    Base(){cout<<"Base construction"<<endl;}
};

class Derived : public Base
{
public:
    using Base::Base;  //�̳�Base�Ĺ��캯��
};

int main()
{
    Base b;
    Derived d;



    return 0;
}
