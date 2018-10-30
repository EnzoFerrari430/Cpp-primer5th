#include <iostream>
#include <string>
#include <map>  //定义了map和multimap
#include <set>  //定义了set和multiset
#include <algorithm>
#include <vector>
using namespace std;
/*
    一个map或set中的关键字必须是唯一的
    multimap和multiset的关键字就没有这个限制,可以重复
*/
int main()
{
    vector<int> vec;
    for(int i = 0; i < 10 ;++i)
    {
        vec.push_back(i);
        vec.push_back(i);
    }
    //初始化set和multiset
    set<int> iset(vec.begin(),vec.end());
    multiset<int> miset(vec.begin(),vec.end());
    cout<<vec.size()<<endl;      //20
    cout<<iset.size()<<endl;     //10
    cout<<miset.size()<<endl;    //20


    return 0;
}
