#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
/*
    有一个文件，列出了一些人和他们的电话号码，有些人只有一个号码 有些有多个
*/
//一个类 保存人名和号码
struct PersonInfo
{
    string name = "aaa";
    vector<string> phones;
};
int main()
{
    string line,word;  //一行记录,每个号码
    vector<PersonInfo> people;
    istringstream record;  //未绑定stringstream对象
    //★使用前一定要记得复位
    while(getline(cin,line))
    {
        record.clear();  //★复位
        PersonInfo info;
        //istringstream record(line);  //定义在while循环外部
        record.str(line);  //将string s拷贝到record中，返回void
        record>>info.name;
        while(record>>word)
            info.phones.push_back(word);
        people.push_back(info);  //将记录加到people末尾
    }

    for(vector<PersonInfo>::iterator vi = people.begin() ;vi != people.end() ;++vi)
    {
        cout<<(*vi).name<<' ';
        for(vector<string>::iterator si = (*vi).phones.begin(); si != (*vi).phones.end() ; ++si)
            cout<<*si<<' ';
        cout<<endl;
    }

    return  0;
}

// 8.12  因为我们需要一个聚合类。 所以它应该没有类的初始化器。




