#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
    只有map和unordered_map有下标运算符
    multimap和unordered_multimap因为关键字和值不是一一对应关系
    set因为没有值

    下标操作
    c[k]        返回关键字是k的元素，如果k不在c中，添加一个关键字为k的元素，并对其进行值初始化
    c.at(k)     访问关键字是k的元素，带参数的检查；若k不在c中，抛出一个out_of_range异常
*/
int main()
{
    map<string,size_t> word_count;  //空map
    word_count["Anna"] = 1;  //word_count中寻找Anna，未找到就创建一个关键字-值对，关键字是"Anna"，值是0 然后再将Anna值附未1

    for(const auto &c : word_count)
    {
        cout<<c.first<<" "<<c.second<<endl;
    }

    /*
        map下标的特性
        通常情况下，解引用一个迭代器所返回的类型与下标运算符返回的类型是一样的。
        但是对map则不然，当对一个map进行下标操作时，会获得一个mapped_type对象(每个关键字关联的类型)，
        但解引用一个map迭代器时，会得到一个value_type对象(map来说pair<const key_type,mapped_type>)

        因为下标操作可能会添加元素，所以map和unordered_map不能是const
    */

    cout<< word_count["Anna"]<<endl;
    ++word_count["Anna"];
    cout<< word_count["Anna"]<<endl;

    map<int,int> v = {
        {1,1},
        {2,2}
    };

    ++v[3];
    cout<<v[3]<<endl;

    return 0;
}
