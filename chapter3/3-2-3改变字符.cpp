#include <iostream>
#include <string>
#include <cctype>
#include <typeinfo>
using namespace std;

int main()
{
    string s1("helloworld");
    //这里要使用引用，如果不使用引用的话,那么对于c而言,他仅仅是s1字符串中某个字符的一个副本.
    //对它使用toupper,改变的是这个副本的大小写,对于原先的字符串并没有任何的改变.
    //c = toupper(c) 实际上改变了c绑定的字符的值
    for(auto &c :s1)
    {
        c = toupper(c);
    }
    cout<<s1<<endl;

    //s2为空，s2[0]的结果将是未定义的
    string s2;
    cout<<s2[0]<<endl;

    string s3("machine gun");
    decltype(s3.size()) index;
    for(index = 0;index != s3.size() && !isspace(s3[index]);index++)
    {
        s3[index] = toupper(s3[index]);
    }
    cout<<s3<<endl;
    cout<<typeid(index).name()<<endl;
    string s4("machine gungungun");
    //decltype(s3.size()) index;
    for(int index = 0;index != s4.size() && !isspace(s4[index]);index++)
    {
        s4[index] = toupper(s4[index]);
    }
    cout<<s4<<endl;

    return 0;
}
