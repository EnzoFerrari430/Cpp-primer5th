#include <iostream>
#include <string>
#include <map>  //������map��multimap
#include <set>  //������set��multiset
#include <algorithm>
#include <vector>
using namespace std;
/*
    һ��map��set�еĹؼ��ֱ�����Ψһ��
    multimap��multiset�Ĺؼ��־�û���������,�����ظ�
*/
int main()
{
    vector<int> vec;
    for(int i = 0; i < 10 ;++i)
    {
        vec.push_back(i);
        vec.push_back(i);
    }
    //��ʼ��set��multiset
    set<int> iset(vec.begin(),vec.end());
    multiset<int> miset(vec.begin(),vec.end());
    cout<<vec.size()<<endl;      //20
    cout<<iset.size()<<endl;     //10
    cout<<miset.size()<<endl;    //20


    return 0;
}
