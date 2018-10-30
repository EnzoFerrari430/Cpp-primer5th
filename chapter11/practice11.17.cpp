#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
    multiset<string> c{"one","two","three","four","five","six","seven"};
    vector<string> v{"111","222","333","444","555","666","777"};
    /*
        ��ͨ�����ܶԹ�������ʹ���㷨���ؼ�����const��һ������ζ�Ų��ܽ������������޸Ļ���������Ԫ�ص��㷨�������㷨Ҫ������д��ֵ
        ʵ���У������һ����������ʹ���㷨��Ҫô�ǵ���һ��Դ���У�Ҫô����һ��Ŀ������
    */
    //copy(v.begin(),v.end(),inserter(c,c.end()));  //��
    //copy(v.begin(),v.end(),inserter(c.end()) );  ����
    //copy(v.begin(),v.end(),back_inserter(c));    ����
    //copy(c.begin(),c.end(),inserter(v,v.end()));    //��
    //copy(c.begin(),c.end(),back_inserter(v));       //��


    //11.18  map_it����   map<string,size_t>::const_iterator

    //11.19
    using compareType = bool (*)(const Sales_data &lhs,const Sales_data &rhs);
    std::multiset<Sales_data,compareType> bookstore(compareIsbn);
    std::multiset<Sales_data,compareType>::iterator c_it = bookstore.begin();
    return 0;
}
