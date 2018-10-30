#include <iostream>
using namespace std;

//一个表达式，比如ival + 5 末尾加上分号就变成了表达式语句
int main()
{
    ;  //空语句
    int ival;
    ival + 5;  //没有实际作用的表达式语句
    cout<<ival;//一条有作用的表达式语句
    int i;;;;;;  //第二个分号是一个空的语句
    return 0;
}
