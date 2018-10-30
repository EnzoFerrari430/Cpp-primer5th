#include <iostream>
#include <string>
using namespace std;
int main()
{
    //5.4-a  iter要先初始化
    string s1 = "hello world";
    string::iterator iter = s1.begin();
    while(/*string::iterator*/ iter != s1.end())
    {

    }
    cout<<s1<<endl;
    //5.4-b  if 不在while的语句块里 所以语句块定义的status在if里是invalid  status要在语句块外部定义

    return 0;
}
