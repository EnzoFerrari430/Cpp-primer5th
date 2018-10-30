#include <iostream>
#include <string>
using namespace std;
bool str_subrange(const string &str1,const string &str2)
{
    //大小相同：此时用普通相等性判断结果作为返回值
    if(str1.size() == str2.size())
        return str1 == str2;    //bingo,  ==运算符返回布尔值
    //得到较短string对象的大小，
    auto size = (str1.size() < str2.size())?str1.size():str2.size();
    //检查两个string对象的对应字符是否相等，以较短的字符串长度为限
    for( decltype(size) i = 0; i != size ; ++i)
    {
        if(str1[i] != str2[i] )
        {
            return;  //wrong 没有返回值
        }
    }
}
int main()
{
    //6.31  局部临时变量或局部对象的引用返回无效,   在函数内部对常量引用做类似赋值拷贝等动作

    return 0;
}
