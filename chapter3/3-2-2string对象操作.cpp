#include <iostream>

using std::string;
using namespace std;
int main()
{
    string s1;
    string s2;
    std::cin>>s1>>s2;
    std::cout<<s1<<endl;

    /*
        string的读操作时，string对象会自动忽略开头的空白（空格，换行等）从第一个真正的字符读起，到下一个空白结束

    */

    //cin>>s2;
    cout<<s2;


    return 0;
}
