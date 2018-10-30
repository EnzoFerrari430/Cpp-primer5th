#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> sval;
    int flag = 0;
    string s1;
    string temp;
    vector<string>::iterator sb;
    while(cin>>s1)
    {
        sval.push_back(s1);
    }
    sb = sval.begin();
    temp = *sb;
    ++sb;
    while(sb != sval.end())
    {
        if( temp == *sb )
        {
            cout<<temp<<endl;
            break;
        }
        else
        {
            temp = *sb;
            ++sb;
        }
    }
    if( sb == sval.end() )
    {
        cout<<"no repeat"<<endl;
    }
    return 0;
}
