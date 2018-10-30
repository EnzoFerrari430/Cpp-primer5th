#include <iostream>
using namespace std;

int main()
{
    //不读取空格
    /*
    string word;
    while(cin>>word)
    {
        cout<<word<<endl;
    }
    */

    //读取空格
    string line;
    //每次读取一整行，直到末尾
    /*
    while(getline(cin,line))
    {
        if(!line.empty())
        {
            //加了判断 直接回车只输出一行
            cout<<line<<endl;
        }

    }
    */

    //string.size()返回字符串的个数
    //size函数返回的是一个无符号的整型数，如果一条表达式已经都size函数了就不要使用int了
    while(getline(cin,line))
    {
        if(line.size()>10)
        {
            cout<<line<<endl;
        }
    }



    return 0;
}
