#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
/*
    ��һ���ļ����г���һЩ�˺����ǵĵ绰���룬��Щ��ֻ��һ������ ��Щ�ж��
*/
//һ���� ���������ͺ���
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




    string line,word;  //һ�м�¼,ÿ������
    vector<PersonInfo> people;
    while(getline(cin,line))
    {
        PersonInfo info;
        istringstream record(line);  //����¼�󶨵��ն������
        record>>info.name;
        while(record>>word)
            info.phones.push_back(word);
        people.push_back(info);  //����¼�ӵ�peopleĩβ
    }

    //����Ϊconst auto &: &�������踳ֵ��ʡȥ�ܶ�ռ���ʱ��  const�ں����ڲ�������Բ��������޸�
    for(const auto &entry : people)
    {
        ostringstream formatted,badnums;  //ѭ����������
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
