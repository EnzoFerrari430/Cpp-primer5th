#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
insert����emplace���ص�ֵ�������������ͺͲ�����
    �������ظ��ؼ��ֵ���������ӵ�һԪ�ص�insert��emplace�汾����һ��pair
    pair��first��Ա��һ����������ָ����и����ؼ��ֵ�Ԫ�ء�
    second��Ա��һ��boolֵ��ָ��Ԫ�ز���ɹ����Ǹ�Ԫ���Ѿ������������С�
    ����Ѿ��������У���insert��������second��ֵΪfalse���������Ԫ�أ���secondֵΪtrue
*/
int main()
{
    map<string,size_t> word_count;  //��map
    string word;
    while(cin>>word)
    {
        auto ret = word_count.insert({word,1});
        if( !ret.second )
        {
            ++ret.first->second;  //����������
        }
    }
    map<string,size_t>::iterator it,ie = word_count.end();
    for(it = word_count.begin();it != ie;++it)
    {
        cout<<it->first<<" occurs "<<it->second<<" times"<<endl;
    }

    return 0;
}
