#include <iostream>
#include <map>
#include <vector>
#include <string>
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
    auto map_it = word_count.cbegin();
    while( map_it != word_count.cend() )
    {
        cout<< map_it->first <<" occurs "<<map_it->second <<" times"<<endl;
        ++map_it;
    }


    return 0;
}
