#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
һ�������Ͳ�����ʾһ��ֵ����һ�����͡�
����ͨ��һ���ض������������ǹؼ���class��typename��ָ�������Ͳ���
*/

template <unsigned N,unsigned M>
int compare(const char (&p1)[N],const char (&p2)[M])
{
    return strcmp(p1,p2);
}

int main()
{
    compare("hi","mom");



    return 0;
}
