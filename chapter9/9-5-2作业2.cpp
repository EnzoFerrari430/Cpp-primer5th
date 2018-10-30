#include <iostream>
#include <string>
using namespace std;
//9.44
string myreplace(string s,const string &oldVal,const string &newVal)
{
    auto num = oldVal.size();
    for(string::size_type i = 0;i < s.size() - num;)
    {
        if(oldVal == s.substr(i,num))
        {
            s.replace(i,num,newVal);
            i += newVal.size();
        }
        else
            ++i;
    }
    return s;
}
int main()
{
    string str{ "To drive straight thru is a foolish, tho courageous act." };
    str = myreplace(str, "tho", "though");
    str = myreplace(str, "thru", "through");
    cout << str << endl;

    return 0;
}
