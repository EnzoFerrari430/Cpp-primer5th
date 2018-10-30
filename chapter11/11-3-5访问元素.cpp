#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
/*
������������Ԫ�صĲ���
lower_bound��upper_bound����������������
�±��at����ֻ�����ڷ�const��map��unordered_map
    c.find(k)  ���ص�һ���ؼ�����k��Ԫ�صĵ���������k���������У��򷵻�β�������
    c.count(k)  ���عؼ��ֵ���k������

    c.lower_bound(k)    ����һ����������ָ���һ���ؼ��ֲ�С��k��Ԫ��
    c.upper_bound(k)    ����һ����������ָ���һ���ؼ��ִ���k��Ԫ��
    c.equal_range(k)    ����һ��������pair����ʾ�ؼ��ֵ���k��Ԫ�صķ�Χ����k�����ڣ�pair��������Ա������c.end()
*/
int main()
{
    //���ֲ���������Ʒ�ķ���
    multimap<string,string> authors = { {"pjd","666"},{"Enzo","C"},{"Enzo","C++"},{"Enzo","Java"},{"Enzo","Python"},{"pp","asdf"} };

    //����1
    auto pos1 = authors.find("Enzo");
    auto cnt1 = authors.count("Enzo");
    while(cnt1)
    {
        cout<<pos1->second<<" ";
        ++pos1;
        --cnt1;
    }
    cout<<endl;

    //����2
    auto beg2 = authors.lower_bound("Enzo");
    auto end2 = authors.upper_bound("Enzo");
    for(;beg2 != end2 ; ++beg2)
    {
        cout<<beg2->second<<" ";
    }
    cout<<endl;

    //����3
    auto pos3 = authors.equal_range("Enzo");
    for(;pos3.first != pos3.second ; ++pos3.first)
    {
        cout<< pos3.first->second<<" ";
    }
    cout<<endl;



    return 0;
}
