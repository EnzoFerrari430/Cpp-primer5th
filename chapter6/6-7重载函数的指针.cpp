#include <iostream>
#include <string>
using namespace std;
/*
    ������ʹ�����غ���ʱ�������ı��������Ľ綨����Ӧ��ѡ���ĸ�����
    ������ͨ��ָ�����;���ѡ���ĸ�������ָ�����ͱ��������غ����е�ĳһ����ȷƥ��
*/
void ff(int *);
void ff(unsigned int);

void (*pf1)(unsigned int) = ff;

//void (*pf2)(int) = ff;  //���� û���κ�һ��ff����β�ƥ��
//double (*pf3)(int *) = ff;  //���� ff��pf3�ķ������Ͳ�ƥ��


//����ָ���β�
//����������ƣ���Ȼ���ܶ��庯�����͵��βΣ������βο�����ָ�������͵�ָ��

//�������β��Ǻ������ͣ������Զ���ת����ָ������ָ��
void useBigger(const string &s1,const string &s2,bool pf(const string &,const string &));
//�ȼ�����  ��ʽ�Ľ��βζ����ָ������ָ��
void useBigger(const string &s1,const string &s2,bool (*pf)(const string &,const string &));

//Ϊ�˱���ֱ��ʹ�ú���ָ�����Ͷ���ɵ��߳�������ʹ�����ͱ�����decltype
//Func��Func2�Ǻ�������
typedef bool Func(const string &,const string &);
typedef decltype(lengthCompare) Func2;  //�ȼ۵�����

//FuncP��FuncP2��ָ������ָ��
typedef bool (*FuncP)(const string &,const string &);
typedef decltype(lengthCompare) *FuncP2;  //�ȼ۵�����
int main()
{

    //����ֱ�ӰѺ�����Ϊʵ��ʹ�ã���ʱ�����Զ�ת����ָ��
    //�Զ�������lengthCompareת����ָ��ú�����ָ��
    useBigger(s1,s2,lengthCompare);

    return 0;
}
