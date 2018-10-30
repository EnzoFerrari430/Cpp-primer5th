#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1,s2;
    int flag = 0;
    while(cin>>s1)
    {
        if(s2 == s1)
        {
            cout<<s1<<endl;
            flag = 1;
            break;
        }
        else
            s2 = s1;
    }
    if( 0 == flag )
    {
        cout<<"no repeat"<<endl;
    }


    return 0;
}
