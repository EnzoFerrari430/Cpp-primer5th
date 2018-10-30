/*
    char ch = getVal();
    int ival = 42;
    switch(ch)
    {
        case 3.14:  //错误 case标签不是一个整数

        case ival:  //错误 case标签不是一个常量
    }

*/

#include <iostream>
using namespace std;
int main()
{
    char ch;
    unsigned int acnt = 0,ecnt = 0,icnt = 0,ocnt = 0,ucnt = 0;
    while(cin>>ch)
    {
        //switch语句首先对括号里的表达式求值,表达式的值转换成整数类型,然后与每个case标签的值比较
        //如果和某个case标签的值匹配成功，程序从该标签后的第一条语句开始执行，直到到达了switch的结尾或遇到了一条break语句
        switch(ch)
        {
        case 'a':
            ++acnt;
            break;
        case 'e':
            ++ecnt;
            break;
        case 'i':
            ++icnt;
            break;
        case 'o':
            ++ocnt;
            break;
        case 'u':
            ++ucnt;
            break;
        }
    }
    cout<<"num a: "<<acnt<<endl;
    cout<<"num e: "<<ecnt<<endl;
    cout<<"num i: "<<icnt<<endl;
    cout<<"num o: "<<ocnt<<endl;
    cout<<"num u: "<<ucnt<<endl;



    return 0;
}
