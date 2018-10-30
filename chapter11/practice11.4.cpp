#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <numeric>
using namespace std;
//ispunct  �������ַ����ط�0  ���򷵻�0
//��������C���԰汾��C++�汾��ispunct����C++�汾��Ҫ��ȫ��������� ::
string to_be_low(string &s)
{
    for( auto &c : s)
    {
        c = tolower(c);
    }
    s.erase(remove_if(s.begin(),s.end(),::ispunct),s.end());
    //s.erase(find_if(s.begin(),s.end(),::ispunct));
    return s;
}
int main()
{
    map<string,size_t> word_count;
    string word;
    while(cin>>word)
    {
        to_be_low(word);
        ++word_count[word];
    }
    //��ӡ���
    for(const auto &w:word_count)
    {
        cout<<w.first<<": occurs: "<<w.second<<( w.second > 1? " times" : " time" )<<endl;
    }
    return 0;
}
