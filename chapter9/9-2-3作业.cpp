#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
/*
9.9
    begin: �ǳ������ҷ�����������ͨ����������
    cbegin: ������Ա���ҷ��������ĳ�������������
*/
//9.10
int main()
{
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v1.cbegin();
    auto it4 = v2.cbegin();
    const int a = 10;
    const int *const p1 = &a;
    const int *p2 = &a;
    cout<<typeid(it1).name()<<endl;
    cout<<typeid(it2).name()<<endl;
    cout<<typeid(it3).name()<<endl;
    cout<<typeid(it4).name()<<endl;
    cout<<typeid(a).name()<<endl;
    cout<<typeid(p1).name()<<endl;
    cout<<typeid(p2).name()<<endl;
    return 0;
}
