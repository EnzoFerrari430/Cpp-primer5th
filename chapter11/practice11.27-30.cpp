#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
/*
    11.27
        对multimap和multiset这种可以用count对关键字进行计数
        对唯一关键字的关联容器就用find代替count使用

    11.28
        find返回关联容器的迭代器,容器类型是map<string,vector<int> >  迭代器是map<string,vector<int> >::iterator

    11.29
        upper_bound和lower_bound都指向一个不影响排序的关键词插入位置
        equal_range迭代器pair都指向关键字可以插入的位置

    11.30
        pos是一个迭代器pair
        pos.first是指向第一个元素的迭代器
        pos.first->second  解引迭代器，得到一个pair，再指向pair的second元素
*/
int main()
{


    return 0;
}
