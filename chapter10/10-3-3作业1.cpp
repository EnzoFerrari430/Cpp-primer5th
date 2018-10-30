#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

void print(vector<string> vec,int leng)
{
    //count_if����һ������ֵ����ʾ���ٴ�Ϊ��
    int num = count_if(vec.begin(),vec.end(),[leng](const string &s){return s.size() > leng;});
    cout<<num<<endl;
}


int main()
{
    string letter;
    vector<string> words;
    while(cin>>letter)
    {
        words.push_back(letter);
    }
    print(words,6);

    return 0;
}
