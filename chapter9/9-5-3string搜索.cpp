#include <iostream>
#include <string>
using namespace std;
/*
    每个搜索函数都返回一个string::size_type值，表示匹配发生的位置，如果匹配失败，则返回一个名为string::npos的static成员。
    标准库将npos定义为一个const string::size_type类型，并初始化为-1.

    string 搜索函数返回一个string::size_type值，该类型是unsigned类型。因此用int或其他带符号类型保存这些函数返回不是一个好主意

    所有的搜索函数都是大小写敏感的。查找时要注意大小写
    find函数完成简单的搜索。它查找参数指定的字符串，若找到，则返回第一个匹配位置的下标，否则返回npos。


string的搜索操作

    s.find(args)                    查找s中args第一次出现的位置
    s.rfind(args)                   查找s中args最后一次出现的位置
    s.find_first_of(args)           在s中查找args中任何一个字符第一次出现的位置
    s.find_last_of(args)            在s中查找args中任何一个字符最后一次出现的位置
    s.find_first_not_of(args)       在s中查找第一个不在args中的字符
    s.find_last_not_of(args)        在s中查找最后一个不在args中的字符

args必须是以下的形式
    c,pos                   从s中位置pos开始查找字符c。pos默认为0
    s2,pos                  从s中位置pos开始查找字符串s2。pos默认为0
    cp,pos                  从s中位置pos开始查找指针cp指向的以空字符结尾的c风格字符串，pos默认为0
    cp,pos,n                从s中位置pos开始查找指针cp指向的数组的前n个字符。pos和n无默认值


*/
int main()
{
    /*
    string name("AnnaBelle");
    auto pos1 = name.find("Anna");  //pos1 == 0
    cout<<pos1<<endl;
    auto pos2 = name.find("annd");  //返回unsigned的-1
    cout<<pos2<<endl;
    */

    /*
    //查找与给定字符串中任何一个字符匹配的位置。
    string numbers("0123456789"),name("r2d2");
    auto pos = name.find_first_of(numbers);  //numbers是给定的字符串
    cout<<pos<<endl;
    */

    /*
    //搜索第一个不在参数中的字符
    string numbers("0123456789");
    string dept("03714p3");
    auto pos = dept.find_first_not_of(numbers);  //搜索第一个不在参数中的字符
    cout<<pos<<endl;
    */


    //逆向搜索rfind成员函数搜索最后一个匹配，
    string river("Mississippi");
    auto first_pos = river.find("is");
    auto last_pos = river.rfind("is");  //查找s中args最后一次出现的位置
    cout<<first_pos<<" "<<last_pos<<endl;

    return 0;
}
