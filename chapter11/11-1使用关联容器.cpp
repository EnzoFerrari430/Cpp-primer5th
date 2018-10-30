#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <string>
using namespace std;
/*
    map:�ؼ���-ֵ�Եļ���  ���ؼ���ӳ�䵽ֵ��
*/
int main()
{
    //���ʼ���
    map<string,size_t> word_count;
    //��set��������Եĵ���
    set<string> exclude = {"the","but","and","or","an","a"};
    string word;
    while(cin>>word)
    {
        //ͳ�Ʋ���exclude�еĵ���
        if(exclude.find(word) == exclude.end())
        {
            //���word��δ��map�У��±�������ᴴ��һ����Ԫ��
            ++word_count[word];  //��ȡword�ļ�����������һ    word�൱��������±�
        }

    }
    //��ӡ���
    for(const auto &w:word_count)
    {
        cout<<w.first<<": occurs: "<<w.second<<( w.second > 1? " times" : " time" )<<endl;
    }
    return 0;
}
