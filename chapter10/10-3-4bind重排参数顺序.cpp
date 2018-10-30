#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;

//比较函数，用按长度排序单词
bool isShort(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string letter;
    vector<string> words;
    while(cin>>letter)
    {
        words.push_back(letter);
    }
    //可以用参数绑定颠倒isShort的含义
    //sort(words.begin(),words.end(),isShort);
    //单词由长至短排序
    sort(words.begin(),words.end(),bind(isShort,_2,_1));
    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
