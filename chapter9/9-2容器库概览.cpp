#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;
/*
��������
���ͱ���
    iterator            ���������͵ĵ���������
    const_iterator      ���Զ�ȡԪ�أ��������޸�Ԫ�صĵ���������
    size_type           �޷����������ͣ��㹻��������������������������Ĵ�С
    difference_type     �������������ͣ��㹻��������������֮��ľ���
    value_type          Ԫ������
    reference           Ԫ�ص���ֵ����
    const_reference     Ԫ�ص�const��ֵ����

���캯��
    C c;                Ĭ�Ϲ��캯��
    C c1(c2);           ����c2�Ŀ���c1
    C c(b,e);           ����c,��������b��eָ���ķ�Χ�ڵ�Ԫ�ؿ�����c(array��֧��)
    C c{a,b,c...};      �б��ʼ��c

��ֵ��swap
    c1 = c2;
    c1 = {a,b,c...}
    a.swap(b)
    swap(a,b)

��С
    c.size()
    c.max_size()        c�ɱ�������Ԫ�ص���Ŀ
    c.empty()

���ɾ��Ԫ��(��������array)
    c.insert(args)      ��args�е�Ԫ�ؿ�����c
    c.emplace(inits)    ʹ��inits����c�е�һ��Ԫ��
    c.erase(args)       ɾ��argsָ����Ԫ��
    c.clear()           ɾ��c�����е�Ԫ��,����void

��ϵ�����
    ==  !=
    <,<=,>,>=

��ȡ������
    c.begin(),c.end()
    c.cbegin(),c.cend() ����const_iterator

���������Ķ����Ա
    reverse_iterator    ������ѰַԪ�صĵ�����
    const_reverse_iterator  �����޸�Ԫ�ص����������
    c.rbegin(),c.rend() ����ָ��c��βԪ�غ���Ԫ��֮ǰλ�õĵ�����
    c.crbegin(),c.crend()����const_reverse_iterator
*/
int main()
{
//��ϰ9.2
    list<deque<int>> li;

    return 0;
}
