#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NoDefault
{
public:
    NoDefault(int a):data(a){}
    int data;
};

class C
{
public:
    NoDefault nd;
    C():nd(0){}
};

int main()
{
    C c;
    cout<<c.nd.data;
    //vector<NoDefault> vec(10);  NoDefaultû��Ĭ�Ϲ��캯�������ܳ�ʼ��
    vector<C> vec(10);  //��ΪC��Ĭ�Ϲ��캯�� ����OK
    return 0;
}

//7.46
//a. ��  ���ṩ���캯�������������Լ��ϳ�һ��Ĭ�Ϲ��캯��
//b. ��  Ϊ��Ա�ṩĬ��ֵ�Ĺ��캯�� Ҳ��Ĭ�Ϲ��캯��
//c. ��  ��Ӧ���ṩĬ�Ϲ��캯��
//d. ��  ֻ��û�ж��幹�캯��ʱ���������Ż�����Ĭ�Ϲ��캯��

