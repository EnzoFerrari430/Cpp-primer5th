#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
    每个流都有一个关联的文件模式，用来指出如何使用文件
        in          以读的方式打开
        out         以写的方式打开
        app         每次写操作前均定位到文件末尾
        ate         打开文件后立即定位到文件末尾
        trunc       截断文件
        binary      以2进制方式打开



    ifstream关联的文件默认in模式打开
    ofstream关联的文件默认out模式打开
    fstream关联的文件默认in和out模式打开

    以out模式打开的文件会丢失已有的数据
*/
int main()
{
    //默认情况下，当我们打开一个ofstream时，文件的内容会被丢弃。阻止一个ofstream清空给定文件内容的方法是同时指定app模式
    //下面这几条语句，file1都会被截断
    ofstream out("file1");  //隐含以输出的模式打开文件并截断文件
    ofstream out2("file1",ofstream::out); //隐含的截断文件
    ofstream out3("file1",ofstream::out | ofstream::trunc);
    //为了保留文件内容，我们必须显式指定app模式
    ofstream app("file1",ofstream::app);  //隐含为输出模式
    ofstream app2("file1",ofstream::out | ofstream::app);


    return 0;
}
