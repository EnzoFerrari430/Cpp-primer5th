#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;

void error_msg(initializer_list<string> il)
{
    for(auto beg = il.begin() ;beg != il.end();++beg)
    {
        cout<<*beg<<' ';
    }
    cout<<endl;
}

int main()
{
    /*
        如果函数实参数量未知，但是全部实参类型都相同，我们可以使用initializer_list类型的形参。
        这是一种标准库类型，用于表示特定类型的值的数组，在同名头文件中

        和vector不一样的是，initializer_list对象中的元素永远都是常量.不能被改变
    */
    string expected = "ok to go";
    string actual = "ok to go1";
    string s;
    cin>>s;
    s.push_back('a');
    if(expected != actual)
        error_msg({"functionx",expected,actual,s});
    else
        error_msg({"functionx","OK"});


    return 0;
}
