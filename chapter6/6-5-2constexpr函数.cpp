#include <iostream>
#include <string>
using namespace std;

/*
    C++11
    constexpr������ָ�����ڳ������ʽ�ĺ�����
    constexpr����Լ��:
        �����ķ������ͼ������β����Ͷ�������ֵ����
        �������ر�������ֻ��һ��return���

        constexpr��һ�����س������ʽ

*/
constexpr int new_sz()
{
    return 42;
}

constexpr int foo = new_sz();
//����ʱ����֤new_sz�������ص��ǳ������ʽ
//ִ��ʱ���������Ѷ�constexpr�����ĵ����滻������ֵ��Ϊ�����ڱ����������ʱչ����constexpr��������ʽָ��Ϊ��������
int main()
{
    cout<<foo<<endl;

    return 0;
}
