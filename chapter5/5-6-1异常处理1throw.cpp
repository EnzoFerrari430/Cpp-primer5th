#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    /*
        异常处理机制为程序中异常处理和异常检测这两个部分的协作提供支持。
        C++中异常处理包括：
            throw 表达式:异常检测部分使用throw表达式来表示它遇到了无法处理的问题。称为throw引发(raise)了异常

            try语句块，异常处理部分使用try语句块处理异常。try语句块以关键字try开始，并以多个catch子句结束。try语句块中代码抛出的异常
            通常会被某个catch子句处理。因为catch子句”处理“异常，通常它们也被称作异常处理代码

            一套异常类，用于在throw表达式和相关的catch子句之间转换异常的具体信息
    */

    int num1,num2;
    num1 = 10;
    num2 = 5;
    try
    {
        if(num1 != num2)
            throw runtime_error("num1,num2 are not same");
    }
    catch(runtime_error err)
    {
        cout<<err.what()<<endl;
    }
    return 0;
}
