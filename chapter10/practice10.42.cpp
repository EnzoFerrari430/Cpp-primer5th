#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <string>
using namespace std;

void elimDups(list<string> &words)
{
    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    words.sort();

    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    words.unique();

    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;
}

int main()
{
    list<string> lst;
    string str;
    while(cin>>str)
    {
        lst.push_back(str);
    }
    elimDups(lst);
    return 0;
}
