#include <iostream>
#include <string>
using namespace std;
void reset(int &i)
{
    i = 0;
}

bool iSshorter(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}
int main()
{
    /*
        ���õĲ���ʵ��������������������������
        �����βε���Ϊ��֮���ơ�ͨ��ʹ�������βΣ��������ı�һ������ʵ�ε�ֵ
    */
    int n = 0, i = 42;
    int &r = n;  //r����n
    r = 42;
    r = i;
    i = r;

    int j = 42;
    cout<<j<<endl;
    reset(j);
    cout<<j<<endl;

    /*
        ʹ�����ñ��⿽��
            ������������Ͷ��������������Ƚϵ�Ч,�е�������������֧�ֿ�����������ĳ�����Ͳ�֧�ֿ�������ʱ������ֻ��ͨ�����÷���

            �����д�Ƚ�2��string����ĳ��ȣ�string������ܻ�ܳ�����ʱҪ���⿽��,��ʹ������,����Ϊstring���䣬���Կ����öԳ���������
    */


    return 0;
}
