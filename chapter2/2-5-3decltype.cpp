#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    /*
        C++11����ڶ�������˵����decltype������������ѡ�񲢷��ز��������������͡�
        �ڴ˹����У��������������ʽ���õ��������ͣ�ȴ��ʵ�ʼ�����ʽ��ֵ

    */
    //int num = 42;
    //int &r = num;
    const int ci = 0,&cj = ci;
    //decltype(num) x;
    decltype(ci) y = ci;  //const�����ñ����ʼ��
    //cout<<typeid(x).name()<<endl;
    //���decltype�ı��ʽ����һ����������decltype���ر��ʽ�����Ӧ������
    int i = 42,*p = &i,&r = i;
    decltype(r) a = r;
    decltype(r + 0) b;  //b ��һ��δ��ʼ����int�ͱ���
    //������ʽ�����ǽ����ò�������decltype���õ���������
    //decltype(*p) c = r;  //c��int & �����ʼ��
    /*
        decltype��auto������
        decltype�Ľ�����ͺͱ��ʽ������ء�

        ע�⣺decltype���õı��ʽ��������������������š���õ��������벻�����ŵ��п��ܻ᲻һ��

    */
    //decltype((i)) d; // 2�����ŵĽ����Զ������
    decltype(i) e;

    return 0;
}
