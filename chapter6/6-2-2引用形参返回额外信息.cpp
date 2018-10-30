#include <iostream>
#include <string>
using namespace std;
string::size_type find_char(const string &s,char c,string::size_type &occurs)
{
    auto ret = s.size();  //第一次出现的位置
    occurs = 0;
    for( decltype(ret) i = 0;i<s.size();++i )
    {
        if( s[i] == c)
        {
            if(ret == s.size() )
                ret = i;
            ++occurs;
        }
    }
    return ret;  //出现次数通过occurs隐式返回
}
int main()
{
    /*
        定义函数，使其返回多个信息
            1.定义一个新的数据类型(我猜可能类似于C的结构体)，让他包含多个数据信息。
            2.给函数传入一个额外的引用实参，令其保存字符出现的次数

    */
    string s;
    string::size_type ctr;  //用来记录出现的次数
    getline(cin,s);
    auto index = find_char(s,'o',ctr);
    cout<<index<<' '<<ctr<<endl;


    return 0;
}
