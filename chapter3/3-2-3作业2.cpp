#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s1;
    cin>>s1;
    int i;
    /*
    for(i = 0;i<s1.size();i++)
    {
        s1[i] = 'X';
    }
    */
    i = 0;
    while(i<s1.size())
    {
        s1[i] = 'X';
        i++;
    }
    cout<<s1<<endl;

    string s2;
    cout<<s2[0]<<endl;  //������ ���ǲ��Ϸ� s2�ǿ��ַ���������Ԥ֪s2[0]��ʲô






    return 0;
}
