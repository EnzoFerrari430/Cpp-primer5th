#include <iostream>
using namespace std;

/*
    ��������ࣨ�ڲ������򣩵ĳ�Ա����ࣨ��������򣩵�ĳ����Աͬ����
    �������ཫ���������������ظû����Ա����ʹ�������Ա�ͻ����Ա���β��б�һ�£�����Ҳ�ᱻ����
*/
class Base
{
public:
    int memfcn();
};

class Derived : public Base
{
public:
    int memfcn(int);  //���ػ����memfcn
};

int main()
{
    Derived d;
    Base b;
    b.memfcn();
    d.memfcn(10);
    //d.memfcn();  �����б�Ϊ�յ�memfcn��������
    d.Base::memfcn();



    return 0;
}
