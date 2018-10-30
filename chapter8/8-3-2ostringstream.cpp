#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
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
    ifstream in("E:\\phonenum.txt");
    if(!in)
    {
        cerr<<"no phone numbers?"<<endl;
        return -1;
    }




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

    //定义为const auto &: &引用无需赋值，省去很多空间与时间  const在函数内部不允许对参数进行修改
    for(const auto &entry : people)
    {
        ostringstream formatted,badnums;  //循环创建对象
        for (const auto &nums : entry.phones)
            if (!valid(nums)) badNums << " " << nums;
            else formatted << " " << format(nums);
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    return  0;
}
