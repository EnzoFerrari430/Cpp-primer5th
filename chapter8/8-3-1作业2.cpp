#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ifstream fr("E:\\Enzo.txt");  //构造ifstream并打开一个文件
    vector<string> sval;
    string str,word;
    while(getline(fr,str))
    {
        sval.push_back(str);
    }

    for(vector<string>::iterator vi = sval.begin();vi != sval.end() ;++vi)
    {
        istringstream record(*vi);  //绑定到读取的行
        while(record >> word)  //将字符输入到word中
            cout<<word<<endl;
    }

    return 0;
}
