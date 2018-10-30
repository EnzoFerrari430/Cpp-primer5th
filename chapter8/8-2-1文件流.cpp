#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string ifile{"E:\\Enzo.txt"};
    //创建文件流对象，如果提供了一个文件名，则open会自动被调用
    ifstream in(ifile);  //构造一个ifstream并打开给定文件


    /*
    ofstream out(ifile);
    for(int i = 0;i<10;++i)
    {
     string str;
     cin>>str;
     out<<str<<"\n";//输出到文件
    }
    */

    /*
    while(in.eof() == 0)  //为真跳出循环
    {
        string str;
        in>>str;
        cout<<str<<endl;
    }
    */
    //in 读取完毕
    in.close();  //关闭文件

    //在要求使用基类型对象的地方，我们可以用继承类型的对象来代替

    return 0;
}
