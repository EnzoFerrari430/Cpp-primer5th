/*
�����ԣ���Ϊʵ����vector<NoDefault>ʱ����������ʵ����vector�����г�Ա����
����������������С�����Ĺ��캯����vector��������캯����ʹ��Ԫ�����͵�Ĭ�Ϲ��캯������Ԫ�ؽ���ֵ��ʼ����
��NoDefaultû��Ĭ�Ϲ��캯�����ᵼ�±������,��������һ��
*/

#include <iostream>
#include <vector>

using namespace std;

class NoDefault
{
public:
    //NoDefault():a(0){}  û�и�Ĭ�Ϲ��캯���ͻᱨ��
    NoDefault(int z):a(z){}
private:
    int a;
};

template class vector<NoDefault>;

int main()
{


    return 0;
}
