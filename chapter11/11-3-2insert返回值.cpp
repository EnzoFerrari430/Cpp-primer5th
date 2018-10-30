#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
insert或者emplace返回的值依赖于容器类型和参数。
    不包含重复关键字的容器，添加单一元素的insert和emplace版本返回一个pair
    pair的first成员是一个迭代器，指向具有给定关键字的元素。
    second成员是一个bool值，指出元素插入成功还是该元素已经存在于容器中。
    如果已经在容器中，则insert不操作，second的值为false，否则插入元素，且second值为true
*/
int main()
{
    map<string,size_t> word_count;  //空map
    string word;
    while(cin>>word)
    {
        auto ret = word_count.insert({word,1});
        if( !ret.second )
        {
            ++ret.first->second;  //递增计数器
        }
    }
    map<string,size_t>::iterator it,ie = word_count.end();
    for(it = word_count.begin();it != ie;++it)
    {
        cout<<it->first<<" occurs "<<it->second<<" times"<<endl;
    }

    return 0;
}
