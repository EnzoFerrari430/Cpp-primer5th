#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
//9.18
int main()
{
    deque<string> ds;
    string str;
    while(cin>>str)
    {
        ds.emplace_back(str);
    }
    for(auto c: ds)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
//9.19 无需变化
