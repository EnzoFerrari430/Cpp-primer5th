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
    string name = "aaa";
    vector<string> phones;
};
int main()
{
    string line,word;  //һ�м�¼,ÿ������
    vector<PersonInfo> people;
    istringstream record;  //δ��stringstream����
    //��ʹ��ǰһ��Ҫ�ǵø�λ
    while(getline(cin,line))
    {
        record.clear();  //�︴λ
        PersonInfo info;
        //istringstream record(line);  //������whileѭ���ⲿ
        record.str(line);  //��string s������record�У�����void
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

// 8.12  ��Ϊ������Ҫһ���ۺ��ࡣ ������Ӧ��û����ĳ�ʼ������




