#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int ia[10];  //在函数体外的自动被初始化为0
string sa[10];  //在函数体外被初始化为空
int main()
{
    string sa2[10];  //被初始化为空
    int ia2[10];  //在函数体内初始化不确定
    for(auto c:sa)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:ia)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:sa2)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:ia2)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
