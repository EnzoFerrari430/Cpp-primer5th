#include <iostream>
#include <string>
using namespace std;
//C++������ʹ��Ϊ��ʼ���ı���������ʼ�������Ͷ���������ڱ�����˵�������£�
//���ʼ��������������ʱ�Żᱻ���õ���䣬�ǿ��Ա�case��ת���ε�����䣬���������ڱ���ʱ����ɵļ���
int main()
{
    //�������д��
    int idx = 2;
    switch(idx)
    {
        string str; //string��һ���࣬��������Լ�����ʽ��ʼ���� ������Ҳ��һ����ʼ�����,Ҳ�п��ܱ�����
        int k = 1;  //����һ����ʼ�����         �����˱����ĳ�ʼ��
    case 1:
        int j = 1;  //��Ҳ��һ����ʼ�����
        break;
    case 2:
        k = 1;
        j = 2;
        cout<<"k: "<<k<<endl;
        cout<<"j: "<<j<<endl;
        break;
    default:
        break;
    }



    return 0;
}
