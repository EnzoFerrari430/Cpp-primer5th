#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s,string::size_type sz)
{
    return s.size() >= sz;
}

//ʹ������
void emliDups(vector<string> &words)
{
    //�ֵ�������
    sort(words.begin(),words.end());
    //�����ض�����
    auto end_unique = unique(words.begin(),words.end());
    //ɾ���ظ�����
    words.erase(end_unique,words.end());
}

void biggis(vector<string> &words,string::size_type sz)
{
    //ɾ���ظ�����
    emliDups(words);

    //����������
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b){return a.size() < b.size();});

    //����һ������sz��λ��
    auto pos = find_if(words.begin(),words.end(),bind(check_size,_1,sz));

    for_each(pos,words.end(),[](const string &a){cout<<a<<' ';});
    cout<<endl;
}

int main()
{
    vector<string> vec;
    string letter;
    while(cin>>letter)
    {
        vec.push_back(letter);
    }
    biggis(vec,4);



    return 0;
}
