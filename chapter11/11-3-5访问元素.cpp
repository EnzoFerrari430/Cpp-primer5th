#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
/*
关联容器查找元素的操作
lower_bound和upper_bound不适用于无序容器
下标和at操作只适用于非const的map和unordered_map
    c.find(k)  返回第一个关键字是k的元素的迭代器，若k不在容器中，则返回尾后迭代器
    c.count(k)  返回关键字等于k的数量

    c.lower_bound(k)    返回一个迭代器，指向第一个关键字不小于k的元素
    c.upper_bound(k)    返回一个迭代器，指向第一个关键字大于k的元素
    c.equal_range(k)    返回一个迭代器pair，表示关键字等于k的元素的范围。若k不存在，pair的两个成员均等于c.end()
*/
int main()
{
    //三种查找作者作品的方法
    multimap<string,string> authors = { {"pjd","666"},{"Enzo","C"},{"Enzo","C++"},{"Enzo","Java"},{"Enzo","Python"},{"pp","asdf"} };

    //方法1
    auto pos1 = authors.find("Enzo");
    auto cnt1 = authors.count("Enzo");
    while(cnt1)
    {
        cout<<pos1->second<<" ";
        ++pos1;
        --cnt1;
    }
    cout<<endl;

    //方法2
    auto beg2 = authors.lower_bound("Enzo");
    auto end2 = authors.upper_bound("Enzo");
    for(;beg2 != end2 ; ++beg2)
    {
        cout<<beg2->second<<" ";
    }
    cout<<endl;

    //方法3
    auto pos3 = authors.equal_range("Enzo");
    for(;pos3.first != pos3.second ; ++pos3.first)
    {
        cout<< pos3.first->second<<" ";
    }
    cout<<endl;



    return 0;
}
