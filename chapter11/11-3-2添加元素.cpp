#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
/*
关联容器的insert成员向容器中添加一个元素或元素范围
map,set,和无序map,set包含不重复的关键字，插入已存在的元素对容器没有影响

对map进行insert操作时，元素的类型必须是pair

关联容器insert操作
    c.insert(v)             v是value_type类型的对象
    c.emplace(args)
    c.insert(b,e)       b,e是迭代器，表示一个范围
    c.insert(il)        il是花括号列表
    c.insert(p,v)       p是一个迭代器，表示从哪里开始搜索新元素应该存储的位置,★p是一个提示，表示新插入元素的位置尽可能靠近p
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
