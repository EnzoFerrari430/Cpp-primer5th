#include <iostream>
using namespace std;

/*
    ��ʱ���ǿ��Ժ��Գ�Ա��ʼ���͸�ֵ�Ĳ��죬���������Ա��const���������õĻ����ͱ��뽫���ʼ��
*/

class ConstRef
{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};

/*
ConstRef::ConstRef(int ii)
{
    //��ֵ
    i = ii;  //��ȷ
    ci = ii;  //����   ���ܸ�const��ֵ
    ri = i;   //����    riû�г�ʼ��
}
*/

//���캯����ʼֵ�б�ֻ˵����ʼ����Ա��ֵ�������޶���ʼ���ľ���ִ��˳��
//��Ա��ʼ��˳�����������ඨ���еĳ���˳��һ��
//�������һ����Ա������һ����Ա����ʼ���ģ���ô��2����Ա�ĳ�ʼ��˳��ͺܹؼ���
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(i){}


int main()
{


    return 0;
}
