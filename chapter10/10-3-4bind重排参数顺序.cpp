#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;

//�ȽϺ������ð��������򵥴�
bool isShort(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string letter;
    vector<string> words;
    while(cin>>letter)
    {
        words.push_back(letter);
    }
    //�����ò����󶨵ߵ�isShort�ĺ���
    //sort(words.begin(),words.end(),isShort);
    //�����ɳ���������
    sort(words.begin(),words.end(),bind(isShort,_2,_1));
    for(auto c: words)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
