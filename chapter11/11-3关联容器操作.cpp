#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
/*
���������Ķ������ͱ���
    key_type        ���������͵Ĺؼ�������
    mapped_type     ÿ���ؼ��ֹ��������ͣ�ֻ������map
    value_type      ����set����key_type��ͬ
                    ����map��Ϊpair<const key_type, mapped_type>
*/
int main()
{
    set<string>::value_type v1;         //v1��һ��string
    set<string>::key_type v2;           //v2��һ��string
    map<string,int>::value_type v3;     //v3��һ��pair<const string,int>
    map<string,int>::key_type v4;       //v4��һ��string
    map<string,int>::mapped_type v5;    //v5��һ��int


    return 0;
}
