#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    char* s1 = "hello ";
    char* s2 = "world";
    //strcat功能
    //把src所指字符串添加到dest结尾处(覆盖dest结尾处的'\0')并添加'\0'
    char *cp = new char[strlen("hello " "world") + 1]();  //所以后面要加() 来默认初始化
    strcat(cp,s1);
    strcat(cp,s2);
    cout<<cp<<endl;


    string s3,s4;
    s3 = "hello ";
    s4 = "world";
    cout<<s3 + s4<<endl;


    delete[] cp;
    return 0;
}
