#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
    Ĭ������£�lambda���ܸı�������ı���������ڴ�����£���lambda�������൱�еĺ��������������һ��const��Ա
    ���lambda������Ϊ�ɱ�ģ������������Ͳ���const���ˡ�


    �����б�ָ��lambda�����ڲ��������ʾֲ������������Ϣ

    10.3.2�������³���
    ��biggies������ʹ��lambda���ʽ���������б�
    auto wc = find_if(words.begin(),words.end(),[sz](const string &a){ return a.size() >= sz; })
*/

class ShortString
{
public:
    bool operator()(const string &s1,const string &s2)const{
        return s1.size()<s2.size();
    }
};

//�������б��lambda���ʽ��Ӧ����
class SizeComp
{
public:
    SizeComp(size_t n):sz(n){}
    bool operator()(const string &s)const{
        return s.size() >= sz;
    }
private:
    size_t sz;
};


int main()
{
    vector<string> vs;
    vs.push_back("hhh");
    vs.push_back("this is me");
    vs.push_back("i am PJD");
    vs.push_back("nimenhao");
    vs.push_back("woxianzaihenkuaile");
    vs.push_back("nimenyeyaohaohaode");

    stable_sort(vs.begin(),vs.end(),ShortString());

    for(auto c: vs)
    {
        cout<<c<<endl;
    }

    //�������б�
    //auto wc = find_if(words.begin(),word.end(),SizeComp(sz));

    return 0;
}
