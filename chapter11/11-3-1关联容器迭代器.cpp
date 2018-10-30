#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    //单词计数
    map<string,size_t> word_count;
    string word;
    while(cin>>word)
    {
        ++word_count[word];  //提取word的计数器，并加一    word相当于数组的下标

    }
    /*
        当解引用一个关联容器迭代器时，我们会得到一个类型为容器的value_type的值引用。
        对map来说，value_type是一个pair类型。first成员保存const的关键字，second成员保存值

        因为set只保存关键字，所以set的迭代器都是const类型的，尽管定义了 iterator和const_iterator类型
    */
    auto map_it = word_count.begin();
    cout<< map_it->first ;
    cout<< " " <<map_it->second<<endl;
    //map_it->first = "new key";  关键字是const类型，不允许修改
    ++map_it->second;


    set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    set<int>::iterator set_it = iset.begin();
    if(set_it != iset.end())
    {
        //*set_it = 42;  只读,不能修改
        cout<< *set_it<<endl;
    }



    return 0;
}
