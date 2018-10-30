#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
    //按字典序排序words，以方便查找单词
    sort(words.begin(),words.end());
    //unique重排输入范围，使得每个单词只出现一次
    //排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
    auto end_unique = unique(words.begin(),words.end());
    //使用向量操作erase删除重复单词
    words.erase(end_unique,words.end());
}

int main()
{
    string str;
    vector<string> sval;
    while(cin>>str)
    {
        sval.push_back(str);
    }
    elimDups(sval);
    for(auto c:sval)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
