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
        cout<<"2���ַ������"<<endl;
    }
    else
    {
        cout<<"2���ַ�������"<<endl;
    }

    const char ca1[] = "helloworld";
    const char ca2[] = "helloworld";

    if(strcmp(ca1,ca2) == 0)
    {
        cout<<"ca1��ca2���"<<endl;
    }


    return 0;
}
