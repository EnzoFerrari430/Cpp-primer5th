#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(vector<string>& words)
{
    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    sort(words.begin(),words.end());

    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    auto end_unique = unique(words.begin(),words.end());

    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    words.erase(end_unique,words.end());


    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;
}

int main()
{
    vector<string> vec;
    string str;
    while(cin>>str)
    {
        vec.push_back(str);
    }
    elimDups(vec);

    return 0;
    //10.10 算法只作用于迭代器，不直接对容器进行操作
}
