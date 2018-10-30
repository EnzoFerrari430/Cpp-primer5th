#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    /*
        try语句块的通用语法是：

        try{
            program-statements
        }
        catch(exception-declaration)
        {
            handler-statements
        }
        catch(exception-declaration)
        {
            handler-statements
        }
        //...
        catch子句的3部分：关键字catch、括号内一个(可能未命名的)对象的声明(称作异常声明 exception declaration)以及一个块

        try语句块中声明的变量在块外部无法访问，特别是在catch子句内也无法访问
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
        cout<<err.what()<<"\nTry Again? Enter y or n"<<endl;
    }
    return 0;
}
