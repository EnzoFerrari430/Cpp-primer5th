#include <iostream>
#include <vector>
#include <string>
using namespace std;
string myreplace(string s,const string &oldVal,const string &newVal)
{
    //ʹ��substr��s�ַ����ҵ�oldVal
    string::size_type num = oldVal.size();
    for(auto i = s.begin(); distance(i,s.end()) >= distance(oldVal.begin(),oldVal.end());)
    {
        if(oldVal == string{i,i+num})  //���������i i+num֮���Ԫ�� ����ҿ�����
        {
            i = s.erase(i,i+num);  //ɾ��������i��i+num  ����һ��ָ�����һ����ɾ����Ԫ��֮��ĵ�����
            s.insert(i,newVal.begin(),newVal.end());
            i += newVal.size();
        }
        else
        {
            ++i;
        }
    }
    return s;
}
int main()
{
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    s = myreplace(s, "tho", "though");
    s = myreplace(s, "thru", "through");
    cout << s << endl;
    return 0;
}
