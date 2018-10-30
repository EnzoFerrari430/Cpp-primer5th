#include <iostream>
#include <vector>
#include <string>
using namespace std;
string myreplace(string s,const string &oldVal,const string &newVal)
{
    //使用substr拆开s字符串找到oldVal
    string::size_type num = oldVal.size();
    for(auto i = s.begin(); distance(i,s.end()) >= distance(oldVal.begin(),oldVal.end());)
    {
        if(oldVal == string{i,i+num})  //构造迭代器i i+num之间的元素 左闭右开区间
        {
            i = s.erase(i,i+num);  //删除迭代器i到i+num  返回一个指向最后一个被删除的元素之后的迭代器
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
