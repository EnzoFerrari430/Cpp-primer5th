#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
    string str;
    vector<string> s1;
    for(;getline(cin,str);)
    {
        s1.push_back(str);
    }

    for(auto it = s1.begin() ; it != s1.end() && !it->empty() ;it++)
    {
        for(auto &c : *it)
        {
            c = toupper(c);
        }
        cout<<*it<<endl;
    }
    //cout




    return 0;
}
