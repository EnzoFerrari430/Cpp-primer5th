#include <iostream>
using namespace std;


//��һ����û�ж����κ��Լ��汾�Ŀ������Ƴ�Ա�������ÿ����static���ݳ�Ա�������ƶ�ʱ���������Ż�Ϊ���ϳ��ƶ����캯�����ƶ���ֵ�������
//�����������ƶ��������͵ĳ�Ա������������ж�Ӧ���ƶ�������������Ҳ���ƶ������Ա
class X
{
public:
    int i;              //�������Ϳ����ƶ�
    std::string s;      //string�������Լ����ƶ�����
};

class hasX
{
public:

    X mem;
};

//�ٶ�Y�������Լ��Ŀ������캯����δ�����Լ����ƶ����캯��
class Y
{
public:
    Y():i(0){};
    Y(const Y &rhs){i = rhs.i;}
    //Y( Y && ) = delete;
    int i;
    const int p = 10;
};

class hasY
{
public:

    hasY() = default;
    hasY( hasY && ) = default;
    Y mem;  //�����Ա�������Լ��Ŀ������캯����δ�����ƶ����캯�������ƶ����캯��������Ϊɾ����
};

int main()
{
    X x,x2 = std::move(x);
    hasY hy,hy2 = std::move(hy);  //���Y���ƶ����캯������Ϊɾ���ģ���������ʽ���û�ʧ��
    return 0;
}
