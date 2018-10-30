#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
/*
����������insert��Ա�����������һ��Ԫ�ػ�Ԫ�ط�Χ
map,set,������map,set�������ظ��Ĺؼ��֣������Ѵ��ڵ�Ԫ�ض�����û��Ӱ��

��map����insert����ʱ��Ԫ�ص����ͱ�����pair

��������insert����
    c.insert(v)             v��value_type���͵Ķ���
    c.emplace(args)
    c.insert(b,e)       b,e�ǵ���������ʾһ����Χ
    c.insert(il)        il�ǻ������б�
    c.insert(p,v)       p��һ������������ʾ�����￪ʼ������Ԫ��Ӧ�ô洢��λ��,��p��һ����ʾ����ʾ�²���Ԫ�ص�λ�þ����ܿ���p
    c.emplace(p,args)
*/
int main()
{
    vector<int> ivec = {2,4,6,8,2,4,6,8};
    set<int> set2;
    set<int>::iterator set_it;
    set2.insert(ivec.begin(),ivec.end());
    for(set_it = set2.begin();set_it != set2.end(); ++set_it)
    {
        cout<<*set_it<<" ";
    }
    cout<<endl;
    set2.insert({1,3,5,7,1,3,5,7});
    for(set_it = set2.begin();set_it != set2.end(); ++set_it)
    {
        cout<<*set_it<<" ";
    }
    cout<<endl;

    auto p = set2.find(1);
    set2.insert(p,12);
    for(set_it = set2.begin();set_it != set2.end(); ++set_it)
    {
        cout<<*set_it<<" ";
    }
    cout<<endl;

    unordered_multiset<int> un_set = {1,3,0,1,0,5,0,2,2,4};
    unordered_multiset<int>::iterator un_set_it;
    auto pos = un_set.find(1);
    un_set.insert(pos,123);
    for(un_set_it = un_set.begin();un_set_it != un_set.end(); ++un_set_it)
    {
        cout<<*un_set_it<<" ";
    }
    cout<<endl;
    return 0;
}
