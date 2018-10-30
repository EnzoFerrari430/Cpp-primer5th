#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <string>
using namespace std;
/*
    map:关键字-值对的集合  将关键字映射到值上
*/
int main()
{
    //单词计数
    map<string,size_t> word_count;
    //用set保存想忽略的单词
    set<string> exclude = {"the","but","and","or","an","a"};
    string word;
    while(cin>>word)
    {
        //统计不在exclude中的单词
        if(exclude.find(word) == exclude.end())
        {
            //如果word还未在map中，下标运算符会创建一个新元素
            ++word_count[word];  //提取word的计数器，并加一    word相当于数组的下标
        }

    }
    //打印结果
    for(const auto &w:word_count)
    {
        cout<<w.first<<": occurs: "<<w.second<<( w.second > 1? " times" : " time" )<<endl;
    }
    return 0;
}
