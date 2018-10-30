#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
    //���ֵ�������words���Է�����ҵ���
    sort(words.begin(),words.end());
    //unique�������뷶Χ��ʹ��ÿ������ֻ����һ��
    //�����ڷ�Χ��ǰ��������ָ���ظ�����֮��һ��λ�õĵ�����
    auto end_unique = unique(words.begin(),words.end());
    //ʹ����������eraseɾ���ظ�����
    words.erase(end_unique,words.end());
}

int main()
{
    string str;
    vector<string> sval;
    while(cin>>str)
    {
        sval.push_back(str);
    }
    elimDups(sval);
    for(auto c:sval)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
