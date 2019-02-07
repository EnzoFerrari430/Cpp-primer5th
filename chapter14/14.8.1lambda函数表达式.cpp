#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
    默认情况下，lambda不能改变它捕获的变量。因此在此情况下，由lambda产生的类当中的函数调用运算符是一个const成员
    如果lambda被声明为可变的，则调用运算符就不是const的了。


    捕获列表指引lambda在其内部包含访问局部变量所需的信息

    10.3.2节有如下程序
    在biggies函数中使用lambda表达式，带捕获列表
    auto wc = find_if(words.begin(),words.end(),[sz](const string &a){ return a.size() >= sz; })
*/

class ShortString
{
public:
    bool operator()(const string &s1,const string &s2)const{
        return s1.size()<s2.size();
    }
};

//带捕获列表的lambda表达式对应的类
class SizeComp
{
public:
    SizeComp(size_t n):sz(n){}
    bool operator()(const string &s)const{
        return s.size() >= sz;
    }
private:
    size_t sz;
};


int main()
{
    vector<string> vs;
    vs.push_back("hhh");
    vs.push_back("this is me");
    vs.push_back("i am PJD");
    vs.push_back("nimenhao");
    vs.push_back("woxianzaihenkuaile");
    vs.push_back("nimenyeyaohaohaode");

    stable_sort(vs.begin(),vs.end(),ShortString());

    for(auto c: vs)
    {
        cout<<c<<endl;
    }

    //带捕获列表
    //auto wc = find_if(words.begin(),word.end(),SizeComp(sz));

    return 0;
}
