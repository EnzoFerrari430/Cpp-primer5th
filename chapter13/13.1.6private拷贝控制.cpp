#include <iostream>
using namespace std;



/*
    ���±�׼����֮ǰ������ͨ�����俽�����캯���Ϳ�����ֵ���������Ϊprivate������ֹ����

*/

class PrivateCopy
{
    //�޷���˵�������������ĳ�ԱĬ����private��
    //�������Ƴ�Ա��private�ģ������ͨ�û������޷�����
    //������Ԫ�ͳ�Ա�����Ծɿ��Կ�������Ϊ����ֹ��Ԫ�ͳ�Ա�������п��������ǽ���Щ�������Ƴ�Ա����Ϊprivate�ģ��������ǲ���������
    PrivateCopy(const PrivateCopy&);
    PrivateCopy &operator=(const PrivateCopy&);

public:
    PrivateCopy() = default;  //ʹ�úϳɵ�Ĭ�Ϲ��캯��
    ~PrivateCopy();  //�û����Զ�������Ͷ��󣬵��޷���������
};

int main()
{


    return 0;
}
