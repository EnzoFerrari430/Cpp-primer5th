#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
    vector<string> s1;
    string str;
    while(cin>>str)
    {
        for(auto &c:str)
        {
            c = toupper(c);  //返回对应的大写字母，如果已经是大写字母则原样输出
        }
        s1.push_back(str);
    }
    for(auto c:s1)
    {
        cout<<c<<endl;
    }
    return 0;
}
