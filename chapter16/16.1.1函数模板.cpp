#include <iostream>
#include <string>
using namespace std;

//дһ���������Ƚ�����ֵ,ÿ�������Ƚ�һ�ָ������͵�ֵ
//���ǿ��ܻᶨ�������غ���
/*
int compare(const string &v1,const string &v2)
{
    if(v1 < v2)
        return -1;
    if(v2 > v1)
        return 1;
    return 0;
}

int compare(const int &v1,const int &v2)
{
    if(v1 < v2)
        return -1;
    if(v1 > v2)
        return 1;
    return 0;
}
*/

/*
������Ψһ�����ǲ��������ͣ�����������ȫһ��

���ǿ�����һ������ģ�壬������Ϊÿ�����Ͷ�����һ���º���

����ģ�����һ����ʽ������������������ض����͵ĺ����汾
*/

//����д�������ģ����ʽ
template <typename T>
int compare(const T &v1,const T &v2)
{
    if(v1 < v2)
        return -1;
    if(v1 > v2)
        return 1;
    return 0;
}
/*
ģ��Ķ����Թؼ���template��ʼ�������һ��ģ������б�
*/

/*
compare������һ��ģ�� ���Ͳ��������Խ�����Ϊ����˵�����������������ͻ�������˵����һ��ʹ�á�
���Ͳ�����������ָ���������ͻ����Ĳ�������
*/
template <typename T> T foo(T* p)
{
    T tmp = *p;

    return tmp;
}

int main()
{

    cout<<compare(3,0)<<endl;
    cout<<compare("hello","world")<<endl;


    return 0;
}
