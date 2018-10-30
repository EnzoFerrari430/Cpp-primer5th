#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

/*
����word_transform�����������̣�����2��ifstream��������һ�������󶨵�����ת���ļ����ڶ��������󶨵�����Ҫת�����ļ�
buildMap��ȡת�������ļ���������һ��map�����ڱ���ת����ӳ��
transform����һ��string���ж����string�Ƿ����ת��������ת��
*/
//����ת��map
map<string,string> buildMap(ifstream &map_file)
{
    map<string,string> trans_map;
    string key;  //Ҫת���ĵ���
    string value;//�滻�������
    //��ȡ��һ�����ʴ���key�У�����ʣ�����ݴ���value
    while( map_file >> key && getline(map_file,value) )
    {
        if(value.size() > 1)
        {
            trans_map[key] = value.substr(1);  //�ڶ�������Ĭ��npos ����stringĩβ,��ȡ��λ��1��ʼ��ĩβ���ַ�,�ؼ��ֳ��ֶ�ξͶ�Ӧ���
            //trans_map.insert({key,value.substr(1)});  //����ؼ����Ѿ���trans_map�У�insertʲô������
        }
        else
        {
            throw runtime_error("no rule for "+ key );
        }
    }
    return trans_map;
}

//ת���ı�
const string & transform(const string &s,const map<string,string> &m)
{
    //11.34  ���ܸĳ� return m[s]  ��Ϊm��const�ģ�m[s]�����Ԫ��
    auto map_it = m.find(s);  //���ص���һ��������
    //�жϵ����ڲ���ת��������
    if(map_it != m.end() )
    {
        return map_it->second;
    }
    else
        return s;
}

void word_transform(ifstream &map_file,ifstream &input)
{
    auto trans_map = buildMap(map_file);  //����ת������
    string text;
    while(getline(input,text))
    {
        istringstream stream(text);  //��ȡÿ������
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
