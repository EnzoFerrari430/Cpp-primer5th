#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
    һЩ�㷨����ֵ���������е�Ԫ�ء�������ʹ�������㷨ʱ������ע��ȷ������ԭ��С���ٲ�С������Ҫ���㷨д�����Ŀ
    �����ķ�Χ���������Ĵ�С����ᱨ��

    fill(iterator,iterator,val);  ����ҿ�
    fill_n(iterator,size,val);
*/
int main()
{
    vector<int> vec{31,654,318,8964,31,549,8,32414};
    fill(vec.begin(),vec.begin() + 5,9);  //  д��Ĵ�С <= ����Ԫ�صĴ�С
    for(auto c : vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    fill_n(vec.begin(),vec.size()-1,3);
    for(auto c : vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    /*
    //�����ڿ������ϵ������Ƶ�дԪ���㷨
    vector<int> ival;
    fill_n(ival.begin(),4,4);
    for(auto c : ival)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    */



    return 0;
}
