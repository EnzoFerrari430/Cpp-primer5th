#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<cctype>//ctype无法打开，包含tolower()函数和ispunct函数
#include<algorithm>
using namespace std;

int main(int argc, char**argv)
{
    //map的定义
    map<string,size_t> word_count;
    fstream in("1.txt");//定义一个输入流
    string word;

    while (in>>word)
    {
        string::iterator it1;
        for (it1 = word.begin(); it1 != word.end(); ++it1)
        {
            *it1 = tolower(*it1);
        }//消灭大小写
        word.erase(remove_if(word.begin(), word.end(), ispunct),word.end());//消灭标点符号
        ++word_count[word];
    }

    //map同样支持迭代器操作
    map<string ,size_t>::iterator mapi;
    for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11支持:const auto &s : word_count
    {
        //两个成员分别代表关键字和对应值
        cout<<mapi->first<<" ";
        cout<<mapi->second<<" "<<endl;
    }

    return 0;
}
