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
            c = toupper(c);  //���ض�Ӧ�Ĵ�д��ĸ������Ѿ��Ǵ�д��ĸ��ԭ�����
        }
        s1.push_back(str);
    }
    for(auto c:s1)
    {
        cout<<c<<endl;
    }
    return 0;
}
