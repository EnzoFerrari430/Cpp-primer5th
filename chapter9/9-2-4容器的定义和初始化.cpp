#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
    array��ԭ����������
    ��һ��ģ�����Tָ����array�д�ŵ��������ͣ�

    �ڶ���������ģ�����ָ����array�Ĺ̶���С��
    namespace std
    {
    template <typename T, size_t N>
    class array;
    }


    ���캯��	˵��
    arrary<T, N> c	Ĭ�Ϲ��캯����N��Ԫ��ȫ��ʹ�á�Ĭ�ϳ�ʼ����Ϊ�������졣
    arrary<T, N> c(other)	�������캯������������other��Ԫ�ص�c�����졣
    arrary<T, N> c = other	�������캯������������other��Ԫ�ص�c�����졣
    arrary<T, N> c(rValue)	�ƶ����죬ʹ����ֵrValue���Ԫ������ʼ��c��
    arrary<T, N> c = rValue	�ƶ����죬ʹ����ֵrValue���Ԫ������ʼ��c��
    arrary<T, N> c = initlist	ʹ�ó�ʼ���б��ʼ��Ԫ��
    */
    array<int,5> ar{1,2,3,4,5};
    array<int,5> ai(ar);

    for(auto c:ai)
    {
        cout<<c<<' ';
    }

    return 0;
}
