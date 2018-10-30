#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/*
    C++11新标准引入了多个函数，可以实现数值数据与标准库string之间的转换

    要转换为数值的string中第一个非空白符必须是数值中可能出现的字符

    如果不能转换，这些函数将抛出一个invalid_argument异常

*/

int main()
{
    int i = 42;
    //string s = to_string(i);  //将整数i转换为字符表示形式  codeblocks 的bug
    string s("123");
    //double d = stod(s);  codeblocks bug
    //int f = atoi(s);



    return 0;
}
