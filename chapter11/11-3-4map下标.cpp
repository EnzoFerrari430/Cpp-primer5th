#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
    ֻ��map��unordered_map���±������
    multimap��unordered_multimap��Ϊ�ؼ��ֺ�ֵ����һһ��Ӧ��ϵ
    set��Ϊû��ֵ

    �±����
    c[k]        ���عؼ�����k��Ԫ�أ����k����c�У����һ���ؼ���Ϊk��Ԫ�أ����������ֵ��ʼ��
    c.at(k)     ���ʹؼ�����k��Ԫ�أ��������ļ�飻��k����c�У��׳�һ��out_of_range�쳣
*/
int main()
{
    map<string,size_t> word_count;  //��map
    word_count["Anna"] = 1;  //word_count��Ѱ��Anna��δ�ҵ��ʹ���һ���ؼ���-ֵ�ԣ��ؼ�����"Anna"��ֵ��0 Ȼ���ٽ�Annaֵ��δ1

    for(const auto &c : word_count)
    {
        cout<<c.first<<" "<<c.second<<endl;
    }

    /*
        map�±������
        ͨ������£�������һ�������������ص��������±���������ص�������һ���ġ�
        ���Ƕ�map��Ȼ������һ��map�����±����ʱ������һ��mapped_type����(ÿ���ؼ��ֹ���������)��
        ��������һ��map������ʱ����õ�һ��value_type����(map��˵pair<const key_type,mapped_type>)

        ��Ϊ�±�������ܻ����Ԫ�أ�����map��unordered_map������const
    */

    cout<< word_count["Anna"]<<endl;
    ++word_count["Anna"];
    cout<< word_count["Anna"]<<endl;

    map<int,int> v = {
        {1,1},
        {2,2}
    };

    ++v[3];
    cout<<v[3]<<endl;

    return 0;
}
