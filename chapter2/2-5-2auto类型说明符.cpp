#include <iostream>
#include <typeinfo>
using namespace std;

/*
C++11�±�׼����˵�����������ñ�����������ȥ�������ʽ���������͡�auto�ñ�����ͨ����ʼֵ���������������
����auto����ı�����һ��Ҫ��ʼֵ��


*/
int main()
{
    //auto i = 0,*p = &i;  //��ȷ��i��������p������ָ��
    //auto sz = 0,pi = 3.14;  //����sz��pi�����Ͳ�һ��

    //�������� ������ auto
    //������ʵ��ʹ�����õĶ��󣬵����ñ�������ʼ��ʱ��auto�������ö����������ȷ��auto������
    int i = 0 ,&r = i;
    auto a = r;
    //cout<<typeid(a).name()<<endl;  //a��������int

    //auto����Ե�����const �ײ�const�ᱣ������
    const int ci = i,&cr = ci;
    auto b = ci;  //b��int��
    auto c = cr;  //c��int��
    auto d = &i;  //d��һ������ָ��(�����ĵ�ַ����ָ��������ָ��) pi
    auto e = &ci; //e��һ��ָ������������ָ��(�Գ�������ȡ��ַ��һ�ֵײ�const) pki
    cout<<typeid(e).name()<<endl;
    cout<<typeid(&ci).name()<<endl;

    //���ϣ���ƶϳ�һ������const������Ҫ��ȷָ��
    const auto f = ci;  //ci����������int��f��const int
    auto &g = ci;  //g��������int
    cout<<typeid(g).name()<<endl;
    //auto &h = 42; �����÷ǳ���������������ֵ
    const auto &j = 42;  //����Ϊ�������ð�����ֵ
    cout<<typeid(j).name()<<endl;

    a = 42;
    b = 42;
    c = 42;
    //d = 42;
    //e = 42;
    //g = 42; const int

    cout<<a<<" "<<b<<" "<<c<<endl;


    return 0;
}
