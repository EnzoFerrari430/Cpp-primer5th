#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <numeric>
using namespace std;
//ispunct  是特殊字符返回非0  否则返回0
//编译器有C语言版本和C++版本的ispunct，用C++版本的要用全局作用域符 ::
string to_be_low(string &s)
{
    for( auto &c : s)
    {
        c = tolower(c);
    }
    s.erase(remove_if(s.begin(),s.end(),::ispunct),s.end());
    //s.erase(find_if(s.begin(),s.end(),::ispunct));
    return s;
}
int main()
{
    map<string,size_t> word_count;
    string word;
    while(cin>>word)
    {
        to_be_low(word);
        ++word_count[word];
    }
    //打印结果
    for(const auto &w:word_count)
    {
        cout<<w.first<<": occurs: "<<w.second<<( w.second > 1? " times" : " time" )<<endl;
    }
    return 0;
}
