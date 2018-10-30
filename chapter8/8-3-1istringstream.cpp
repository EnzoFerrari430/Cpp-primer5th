#include <iostream>
#include <sstream>
#include <vector>
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

    for(vector<PersonInfo>::iterator vi = people.begin() ;vi != people.end() ;++vi)
    {
        cout<<(*vi).name<<' ';
        for(vector<string>::iterator si = (*vi).phones.begin(); si != (*vi).phones.end() ; ++si)
            cout<<*si<<' ';
        cout<<endl;
    }

    return  0;
}
