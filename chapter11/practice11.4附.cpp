#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<cctype>//ctype�޷��򿪣�����tolower()������ispunct����
#include<algorithm>
using namespace std;

int main(int argc, char**argv)
{
    //map�Ķ���
    map<string,size_t> word_count;
    fstream in("1.txt");//����һ��������
    string word;

    while (in>>word)
    {
        string::iterator it1;
        for (it1 = word.begin(); it1 != word.end(); ++it1)
        {
            *it1 = tolower(*it1);
        }//�����Сд
        word.erase(remove_if(word.begin(), word.end(), ispunct),word.end());//���������
        ++word_count[word];
    }

    //mapͬ��֧�ֵ���������
    map<string ,size_t>::iterator mapi;
    for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
    {
        //������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
        cout<<mapi->first<<" ";
        cout<<mapi->second<<" "<<endl;
    }

    return 0;
}
