#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
bool isBig(const string &s1)
{
    return s1.size() > 4;
}
int main()
{
    string str;
    vector<string> words;
    while(cin>>str)
    {
        words.push_back(str);
    }
    auto end_pos = partition(words.begin(),words.end(),isBig);
    words.erase(end_pos,words.end());
    for(const auto &c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    return 0;
}
