#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int txt_size()
{
    return 3;
}
int main()
{
    unsigned buf_size = 1024;
    int ia[buf_size];
    int ib[4*7-14];
    int ic[txt_size()];
    //int st[11] = "fundamental";  //越界了，括号封闭不了



    return 0;
}
