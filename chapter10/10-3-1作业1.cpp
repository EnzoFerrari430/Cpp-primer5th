#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void emliDups(vector<string> &words)
{
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size()<s2.size();
}

int main()
{
    string str;
    vector<string> vec;
    while(cin>>str)
    {
        vec.push_back(str);
    }
    emliDups(vec);
    //stable_sort(vec.begin(),vec.end(),isShorter);
    for(const auto &c: vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    stable_sort(vec.begin(),vec.end(),isShorter);
    for(const auto &c: vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;




    return 0;
}
