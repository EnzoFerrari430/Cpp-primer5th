#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1 == s2)
    {
        cout<<"字符等长"<<endl;
    }
    else
    {
        cout<<"不一样长，长的是"<<(s1>s2?s1:s2)<<endl;
    }



    return 0;
}
