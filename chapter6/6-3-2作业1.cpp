#include <iostream>
#include <string>
using namespace std;
bool str_subrange(const string &str1,const string &str2)
{
    //��С��ͬ����ʱ����ͨ������жϽ����Ϊ����ֵ
    if(str1.size() == str2.size())
        return str1 == str2;    //bingo,  ==��������ز���ֵ
    //�õ��϶�string����Ĵ�С��
    auto size = (str1.size() < str2.size())?str1.size():str2.size();
    //�������string����Ķ�Ӧ�ַ��Ƿ���ȣ��Խ϶̵��ַ�������Ϊ��
    for( decltype(size) i = 0; i != size ; ++i)
    {
        if(str1[i] != str2[i] )
        {
            return;  //wrong û�з���ֵ
        }
    }
}
int main()
{
    //6.31  �ֲ���ʱ������ֲ���������÷�����Ч,   �ں����ڲ��Գ������������Ƹ�ֵ�����ȶ���

    return 0;
}
