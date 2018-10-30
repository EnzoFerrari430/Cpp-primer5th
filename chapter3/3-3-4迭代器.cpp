#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <typeinfo>
using namespace std;
int main()
{
    /*
        和指针不一样的是，获取迭代器不是使用取地址府，有迭代器的类型同时拥有返回迭代器的成员。
        比如，这些类成员都拥有名为begin和end的成员，其中begin成员负责返回指向第一个元素的迭代器。
        b表示v的第一个元素，e表示尾元素的下一个位置
        auto b = v.begin(),e = v.end();

    */
    string s("some string");
    //判断s是否是空
    if(s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout<<s<<endl;
    /*
        在if内部声明一个迭代器变量it并用begin返回的结果赋给它，这样就得到指示s中的第一个字符的迭代器,接下来通过解引运算符将第一个字符更改为
        大写形式
    */

    //把第一个单词改为大写
    string str;
    getline(cin,str);
    for(auto it = str.begin();it!= str.end() && !isspace(*it);it++)
    {
        *it = toupper(*it);
    }
    cout<<str<<endl;
    vector<int> v;
    const vector<int> cv;
    auto it = v.begin();  //vector<int>::iterator
    auto it2 = cv.begin();//vector<int>::const_iterator
    cout<<typeid(it).name()<<endl;
    cout<<typeid(it2).name()<<endl;
    //const int num;
    //如果对象只读而不用写操作的话最好是const_iterator类型，得到const_iterator类型C++11标准引入2个新函数cbegin和cend
    auto it3 = v.cbegin();//vector<int>::const_iterator
    cout<<typeid(it3).name()<<endl;
    return 0;
}
