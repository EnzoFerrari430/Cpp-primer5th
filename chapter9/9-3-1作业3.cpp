#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string word;
    vector<string> vs;
    auto iter = vs.begin();
    while(cin>>word)
    {
        iter = vs.insert(iter,word);
    }
    for(auto c:vs)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    return 0;
}
