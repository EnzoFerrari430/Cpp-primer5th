#include <iostream>
using namespace std;
int main()
{
    //ostream os;
    //os<<"please enter a value: "<<endl;
    cout<<"hello world 1";
    cout<<"hello world 2";
    cout<<"hello world 3";
    cout<<"hello world 4";
    cout<<"hello world 5";
    cout<<"hello world 6";
    cout<<"hello world 7";
    cout<<"hello world 8";
    cout<<"hello world 9";
    cout<<"hello world 10";
    cout<<"hello world 11";
    cout<<"hello world 12";
    cout<<"hello world 13";
    cout<<"hello world 14";
    cout<<"hello world 15";
    cout<<"hello world 16";
    //�����ı��� ����������ӡ�����ܱ�����ϵͳ�����ڻ������У�����ӡ

    //���»���ˢ��(��������д������豸���ļ�)��ԭ��
    //1.������������
    //2.��������ʱ����Ҫˢ�»��壬�����µ����ݲ��ܼ���д�뻺����
    //3.ʹ�ò�������endl����ʽ��ˢ�»�����
    //4.ÿ���������֮��ʹ�ò�����unitbuf���������ڲ�״̬������ջ�����
    //5.һ�����������������һ��������������£�����д����������ʱ�������������Ļ������ᱻˢ��

    //ˢ�����������
    cout<<"Hi!"<<endl;  //������в�ˢ��
    cout<<"Hi!"<<flush; //ˢ�»�����
    cout<<"Hi!"<<ends;  //����ո�ˢ��



    //unitbuf���ݷ�:����������������ÿ��д����֮�󶼽���һ��flush������
    //nounitbuf���ݷ�:����������ʹ��ָ�ʹ��������ϵͳ����Ļ�����ˢ�»���
    cout<<unitbuf;  //������������󶼻�����ˢ�»�����
    cout<<nounitbuf;//�ص������ķ�ʽ



    //��������������
    //��һ����������������һ�������ʱ���κ���ͼ����������ȡ���ݵĲ���������ˢ�¹��������������׼�⽫cout��cin������һ��
    int n;
    cin>>n;  //֮ǰ������cout�������е����ݶ��ᱻˢ�´�ӡ����

    return 0;
}
