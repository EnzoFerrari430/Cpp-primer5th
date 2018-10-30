#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    //���ʼ���
    map<string,size_t> word_count;
    string word;
    while(cin>>word)
    {
        ++word_count[word];  //��ȡword�ļ�����������һ    word�൱��������±�

    }
    /*
        ��������һ����������������ʱ�����ǻ�õ�һ������Ϊ������value_type��ֵ���á�
        ��map��˵��value_type��һ��pair���͡�first��Ա����const�Ĺؼ��֣�second��Ա����ֵ

        ��Ϊsetֻ����ؼ��֣�����set�ĵ���������const���͵ģ����ܶ����� iterator��const_iterator����
    */
    auto map_it = word_count.begin();
    cout<< map_it->first ;
    cout<< " " <<map_it->second<<endl;
    //map_it->first = "new key";  �ؼ�����const���ͣ��������޸�
    ++map_it->second;


    set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    set<int>::iterator set_it = iset.begin();
    if(set_it != iset.end())
    {
        //*set_it = 42;  ֻ��,�����޸�
        cout<< *set_it<<endl;
    }



    return 0;
}
