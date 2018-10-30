#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    list<string> li;
    while(cin>>str)
    {
        li.push_back(str);
    }
    string sata{"hello"};
    int cnt = count(li.begin(),li.end(),sata);
    cout<<cnt<<endl;


    return 0;
}
