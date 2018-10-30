#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    string letter;
    set<string> words;
    while(cin>>letter)
    {
        words.insert(letter);
    }

    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;



    return 0;
}
