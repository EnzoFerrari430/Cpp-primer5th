#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
    multiset<string> c{"one","two","three","four","five","six","seven"};
    vector<string> v{"111","222","333","444","555","666","777"};
    /*
        ★通常不能对关联容器使用算法，关键字是const这一特性意味着不能将关联容器给修改或重拍容器元素的算法，这类算法要向容器写入值
        实际中，如果对一个关联容器使用算法，要么是当做一个源序列，要么当做一个目标序列
    */
    //copy(v.begin(),v.end(),inserter(c,c.end()));  //行
    //copy(v.begin(),v.end(),inserter(c.end()) );  不行
    //copy(v.begin(),v.end(),back_inserter(c));    不行
    //copy(c.begin(),c.end(),inserter(v,v.end()));    //行
    //copy(c.begin(),c.end(),back_inserter(v));       //行


    //11.18  map_it类型   map<string,size_t>::const_iterator

    //11.19
    using compareType = bool (*)(const Sales_data &lhs,const Sales_data &rhs);
    std::multiset<Sales_data,compareType> bookstore(compareIsbn);
    std::multiset<Sales_data,compareType>::iterator c_it = bookstore.begin();
    return 0;
}
