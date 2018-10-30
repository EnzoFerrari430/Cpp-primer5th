#include <iostream>
#include <list>
using namespace std;
/*
    ���ǿ�����resize���������С������������һ��array��֧��resize��
    �����ǰ��С������Ҫ��Ĵ�С�������󲿵�Ԫ�ػᱻɾ��
    �����ǰ��СС���µĴ�С���Ὣ��Ԫ����ӵ������ĺ�


c.resize(n)     ����cΪ��СΪn��Ԫ�أ���nС�ڱ����С��ɾ������Ԫ�أ����ھ��ں������Ĭ��ֵ
c.resize(n,t)   ����cΪ��СΪn��Ԫ�أ���nС�ڱ����С��ɾ������Ԫ�أ����ھ��ں������ֵΪt��Ԫ��
*/
int main()
{
    list<int> ilist(10,42);  //10��42
    ilist.resize(15);  //��5��ֵΪ0��Ԫ����ӵ�ilist��ĩβ
    for(auto c: ilist)
        cout<<c<<' ';
    cout<<endl;
    ilist.resize(25,-1);  //��10��ֵΪ-1��Ԫ����ӵ�ilist��ĩβ
    for(auto c: ilist)
        cout<<c<<' ';
    cout<<endl;
    ilist.resize(5);    //������20��Ԫ��ɾ��
    for(auto c: ilist)
        cout<<c<<' ';
    cout<<endl;

    return 0;
}
