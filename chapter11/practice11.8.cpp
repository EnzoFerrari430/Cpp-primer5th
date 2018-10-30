#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    string letter;
    vector<string> words;
    while(cin>>letter)
    {
        words.push_back(letter);
    }
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end())
    for(auto c : words)
    {
        cout<<c<<' ';
    }



    return 0;
}
