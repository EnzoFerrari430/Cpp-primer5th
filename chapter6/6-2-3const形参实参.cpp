#include <iostream>
#include <string>
using namespace std;
void reset(int *p)
{
    *p = 123;
    p = 0;
}
void Rreset(int &r)
{
    r = 456;
}
int main()
{
    /*
        ǰ�ģ�����const�����ڶ�����

        ����ʵ�γ�ʼ���β�ʱ������Ե�����const

        ���ǿ���ʹ�÷ǳ�����ʼ��һ���ײ�const���󣬵��Ƿ���������
        һ����ͨ�����ñ�����ͬ���͵Ķ����ʼ��
    */
    /*
    int i = 42;
    const int &r = i;
    //r = 3;
    cout<<r<<endl;
    */
    /*
    int p1 = 32;
    int &rp = p1;
    p1 = 3;
    cout<<rp<<endl;
    */

    /*
    const int p1 = 32;
    int *pp = &p1;  //������ָ��const int �����ָ���ʼ��int *
    */

    int i = 0;
    const int ci = i;
    //&ci//ָ��const int�����ָ��
    const int *p = &ci;
    string::size_type ctr = 0;

    reset(&i);  //��ȷ
    //reset(&ci);
    //reset(p);  //������ָ��const int �����ָ���ʼ��int *
    //Rreset(ci);  //����ͨ������Ч�ĳ�ʼ����������const��������ʼ��
    //Rreset(42);  //����������ֵ��������ʼ����ͨ����
    //Rreset(ctr); //2�����Ͳ�ͬ ctr���޷�����

    //Ҫ�����int�������͵ĺ���������ʹ������ֵ����ֵ���Ϊint�͵ı��ʽ����Ҫת���Ķ������const int���͵Ķ���
    //Ҫ�����intָ�����͵ĺ�����ֻ��ʹ��int *



    return 0;
}
