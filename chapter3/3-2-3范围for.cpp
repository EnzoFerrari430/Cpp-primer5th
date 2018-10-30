#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
    C++11新标准
    返回for，这种语句遍历给定序列中的每个元素并对新序列中的每个值执行某种操作

    语法:
        for(declaration : expression)
            statement
    expression 是一个对象，用于表示一个序列
    declaration 负责定义一个变量，该变量将用于访问序列中的基础元素
    每一次迭代 declaration的变量会被初始化为expression部分的下一个元素值


*/
int main()
{
    string s1("some string");
    for(auto c : s1)
    {
        cout<<c<<endl;
    }

    string s2("hello world!!!!!");
    decltype(s2.size()) count = 0;
    for(auto d : s2)
    {
        if(ispunct(d))  //判断字符是否是标点符号
        {
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
