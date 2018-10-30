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
    while(cin>>s1)
    {
        if( s1[0] >'Z' || s1[0] < 'A')
            continue;

         if(temp == s1)
        {
            cout<<s1<<endl;
            flag = 1;
            break;
        }
        else
            temp = s1;
    }
    if( 0 == flag )
        cout<<"no repeat"<<endl;
    return 0;
}
