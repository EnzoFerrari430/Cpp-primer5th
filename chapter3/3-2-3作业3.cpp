#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    const string s = "Keep out!";
    for(auto &c : s)
    {
        //不能给c赋值，c赋值就是修改了字符串s
        //c = 'x';
        //cout<<s<<endl;
    }
    string s1;
    cin>>s1;
    string::size_type i;
    for(i = 0; i<s1.size(); i++)
    {
        if(!ispunct(s1[i]))
        {
            //直接把不是标点的输出就好了!!!! 怎么没想到呢，强行在原来的字符串上删。。。
            cout<<s1[i];
        }
    }





    return 0;
}
