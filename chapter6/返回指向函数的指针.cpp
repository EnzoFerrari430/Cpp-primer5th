#include <iostream>
#include <string>
using namespace std;
/*
    ���������ƣ���Ȼ���ܷ���һ�������������ܷ���ָ�������͵�ָ�롣Ȼ��������ѷ�������д��ָ�����ʽ��
    �����������Զ��Ľ������������͵��ɶ�Ӧ��ָ������


*/
//��Ҫ����һ�����غ���ָ��ĺ�������򵥵İ취����ʹ�����ͱ���
using F = int(int *,int);    //F�Ǻ������ͣ�����ָ��
using PF = int(*)(int *,int);//PF��ָ������


PF f1(int);
//F f1(int);  //����  f1��Ϊ�������ܷ��غ���
F *f1(int); //��ȷ    ��ʽ��ָ������������ָ������ָ��

//��Ȼ Ҳ��ֱ������
int (*fi(int))(int *,int);

//β�÷�������
auto f1(int)->int (*)(int *,int);


//��auto��decltype���ں���ָ������
string::size_type sumLength(const string &,const string &);
string::size_type largerLength(const string &,const string &);
//�������βε�ȡֵ��getFcn��������ָ��sumLength����largerLength��ָ��
decltype(sumLength) *getFcn(const string &);


int main()
{

    return 0;
}
