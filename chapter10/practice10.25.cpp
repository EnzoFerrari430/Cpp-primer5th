#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s,string::size_type sz)
{
    return s.size() >= sz;
}

//使用引用
void emliDups(vector<string> &words)
{
    //字典序排序
    sort(words.begin(),words.end());
    //消除重读单词
    auto end_unique = unique(words.begin(),words.end());
    //删除重复单词
    words.erase(end_unique,words.end());
}

void biggis(vector<string> &words,string::size_type sz)
{
    //删除重复单词
    emliDups(words);

    //按长度排序
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b){return a.size() < b.size();});

    //查找一个大于sz的位置
    auto pos = find_if(words.begin(),words.end(),bind(check_size,_1,sz));

    for_each(pos,words.end(),[](const string &a){cout<<a<<' ';});
    cout<<endl;
}

int main()
{
    vector<string> vec;
    string letter;
    while(cin>>letter)
    {
        vec.push_back(letter);
    }
    biggis(vec,4);



    return 0;
}
