#include <iostream>
#include <string>
using namespace std;
/*
string类定义了2个额外的成员函数，append和replace，这2个函数可以改变string内容。append的操作是在string末尾进行插入操作的一种简写形式

修改string的操作
s.replace(range,args)       删除range内的字符，替换为args指定的字符。range或者是一个下标和一个长度，或者是一对指向s的迭代器，
                            返回一个指向s的引用
s.erase(pos,len)            删除从位置pos开始的len个字符，如果len被省略则删除从pos开始直到末尾的所有字符,返回一个指向s的引用

s.insert(pos,args)          在pos位置之前插入args指定的字符，pos可以是下标或迭代器，下标版本返回一个s引用，
                            迭代器版本返回插入第一个字符的迭代器


*/
int main()
{
    string s("C++ Primer"),s2 = s;
    s.insert(s.size()," 4th Ed");
    s2.append(" 4th Ed");  //等价方法： 将" 4th Ed"追加到s2
    cout<<s<<endl;
    cout<<s2<<endl;
    //replace操作是调用erase和insert的一种简写形式
    //将" 4th Ed"替换成" 5th Ed"
    //cout<<s[11]<<endl;
    s.erase(11,3);  //从11位开始 删除3位元素  起始位置是0
    s.insert(11,"5th");
    //从位置11开始，删除3个字符并插入"5th"
    s2.replace(11,3,"5th");
    cout<<s<<endl;
    cout<<s2<<endl;
    string ss("hello world!!!!!!");
    auto c = ss.begin();
    //ss.insert(c+5,{'1','2','3'});
    auto d = ss.insert(c+5,'a');
    cout<<ss<<endl;
    cout<<*d<<endl;
    return 0;
}
