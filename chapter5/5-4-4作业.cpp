#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1,str2;
    do
    {
        cin>>str1>>str2;
        if(str1.size() < str2.size())
        {
            cout<<str1<<endl;
        }
        else if(str1.size() > str2.size() )
        {
            cout<<str2<<endl;
        }
        else
        {
            cout<<str1<<endl<<str2<<endl;
        }
    }
    while(cin);  //while(cin)  =====> while(!cin.fail())
    //cin是一个流对象，而>>运算符返回左边的流对象，也就是说cin>>val返回cin，
    //于是while(cin)等同于while(cin>>val)，也就是流是否读取成功


    return 0;
}
