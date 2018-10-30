#include <iostream>
#include <string>
using namespace std;

const string &shorterString(const string &s1,const string &s2)
{
    return s1.size() <= s2.size()? s1: s2;
}
//这个函数的参数和返回值都是const string的引用，当我们需要得到一个普通的引用，使用const_cast可以做到这一点
string &shorterString(string &s1,string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1),const_cast<const string &>(s2));
    return const_cast<string &>(r);
}
int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    //因为返回是const string的引用，所以不能修改
    shorterString(s1,s2)[0] = 'H';
    //现在，先将实参转换成对const的引用，调用const版本的shortString函数，返回一个const string引用，这个引用实际上绑定在了某个初始的
    //非常量实参上，因此我们可以再将其转换回一个普通的string &
    //shorterString('a');  匹配不到函数,参数不对

    cout<<s1<<endl;


    //作业6.39
    //a. 错误★但是编译不报错 这个const是顶层const 不影响传入函数的对象，这里重复声明
    //b. 错误★不允许两个函数除了返回类型外，其他所有要素都相同
    //c. 正确
    return 0;
}
