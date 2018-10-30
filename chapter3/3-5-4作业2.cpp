#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>
#include <cctype>
#include <vector>
using namespace std;
int main()
{
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    if(str1 == str2)
    {
        cout<<"2个字符串相等"<<endl;
    }
    else
    {
        cout<<"2个字符串不等"<<endl;
    }

    const char ca1[] = "helloworld";
    const char ca2[] = "helloworld";

    if(strcmp(ca1,ca2) == 0)
    {
        cout<<"ca1和ca2相等"<<endl;
    }


    return 0;
}
