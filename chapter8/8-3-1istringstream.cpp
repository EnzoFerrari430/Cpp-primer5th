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
    string name;
    vector<string> phones;
};
int main()
{
    string line,word;  //一行记录,每个号码
    vector<PersonInfo> people;
    while(getline(cin,line))
    {
        PersonInfo info;
        istringstream record(line);  //将记录绑定到刚读入的行
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
