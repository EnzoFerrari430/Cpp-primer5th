#include <iostream>
#include <map>
#include <vector>
#include <string>
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
    auto map_it = word_count.cbegin();
    while( map_it != word_count.cend() )
    {
        cout<< map_it->first <<" occurs "<<map_it->second <<" times"<<endl;
        ++map_it;
    }


    return 0;
}
