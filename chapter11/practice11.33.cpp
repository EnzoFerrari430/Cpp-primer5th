#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

/*
函数word_transform管理整个过程，接受2个ifstream参数，第一个参数绑定到单词转换文件，第二个参数绑定到我们要转换的文件
buildMap读取转换规则文件，并创建一个map，用于保存转换的映射
transform接受一个string，判断这个string是否存在转换，有则转换
*/
//建立转换map
map<string,string> buildMap(ifstream &map_file)
{
    map<string,string> trans_map;
    string key;  //要转换的单词
    string value;//替换后的内容
    //读取第一个单词存入key中，行中剩余内容存入value
    while( map_file >> key && getline(map_file,value) )
    {
        if(value.size() > 1)
        {
            trans_map[key] = value.substr(1);  //第二个参数默认npos 就是string末尾,截取从位置1开始到末尾的字符,关键字出现多次就对应最后
            //trans_map.insert({key,value.substr(1)});  //如果关键字已经在trans_map中，insert什么都不做
        }
        else
        {
            throw runtime_error("no rule for "+ key );
        }
    }
    return trans_map;
}

//转换文本
const string & transform(const string &s,const map<string,string> &m)
{
    //11.34  不能改成 return m[s]  因为m是const的，m[s]会添加元素
    auto map_it = m.find(s);  //返回的是一个迭代器
    //判断单词在不在转换规则中
    if(map_it != m.end() )
    {
        return map_it->second;
    }
    else
        return s;
}

void word_transform(ifstream &map_file,ifstream &input)
{
    auto trans_map = buildMap(map_file);  //保存转换规则
    string text;
    while(getline(input,text))
    {
        istringstream stream(text);  //读取每个单词
        string word;
        bool firstword = true;
        while(stream>>word)
        {
            if(firstword)
                firstword = false;
            else
                cout<<" ";
            cout<< transform(word,trans_map);
        }
        cout<<endl;
    }
}
int main()
{
    ifstream if_map("E:\\CC++\\C++ primer\\chapter11\\trans.txt"),if_mes("E:\\CC++\\C++ primer\\chapter11\\message.txt");
    if(if_map && if_mes)
    {
        word_transform(if_map,if_mes);
    }
    else
        cerr<<"can't find the document."<<endl;

    return 0;
}
