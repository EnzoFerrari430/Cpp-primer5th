#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*

    ��׼�ⶨ����һ���ʾ�������������ϵ��������߼���������ࡣÿ����ֱ�����һ��ִ�����������ĵ��ö���

*/



int main()
{
    plus<int> intAdd;  //����ִ��int�ӷ��ĺ�������
    negate<int> intNegate;  //���Զ�intֵȡ���ĺ�������

    int sum = intAdd(10,20);
    cout<<sum<<endl;
    sum = intNegate(intAdd(10,20));
    cout<<sum<<endl;

    //Ĭ�ϵ�sort�����㷨ʹ��operator<�����а����������С�
    //���Ҫִ�н���Ļ������Դ���һ��greater���͵Ķ��󡣸��ཫ����һ�����������������ִ�д��������͵Ĵ������㡣
    vector<string> svec;
    //����һ����ʱ�ĺ�����������ִ������string�����>�Ƚ�����
    sort(svec.begin(),svec.end(),greater<string>());

    vector<string *> nameTable;  //ָ���vector
    //���� nameTable�е�ָ��˴�֮��û�й�ϵ������<������δ�������Ϊ
    sort(nameTable.begin(),nameTable.end(),[](string *a,string *b){return a < b;});
    //��ȷ�� ��׼��涨ָ���less�Ƕ������õġ�
    sort(nameTable.begin(),nameTable.end(),less<string *>());




    return 0;
}
