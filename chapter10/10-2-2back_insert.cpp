#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;
/*
    �����������һ�������������Ԫ�صĵ�����
    ������ͨ��һ��������������Ԫ�ظ�ֵʱ��ֵ�����������ָ���Ԫ�ء�
    ��������ͨ�������������ֵʱ��һ���븳ֵ���Ҳ�ֵ��ȵ�Ԫ�ر���ӵ������С�


    back_inserter����һ��ָ�����������ã�����һ����������󶨵Ĳ����������
    ͨ���˵�������ֵʱ����ֵ����������push_back��һ�����ж�ֵ��Ԫ����ӵ�������
*/
int main()
{
    /*
    vector<int> vec;  //������
    auto it = back_inserter(vec);  //  ����һ����������󶨵Ĳ����������ͨ������ֵ�ὫԪ����ӵ�vec��ȥ
    *it = 42;
    for(auto c : vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    cout<<vec.size()<<endl;
    */


    vector<int> vec;
    fill_n(back_inserter(vec),10,0);
    for(auto c : vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    cout<<vec.size()<<endl;


    return 0;

}
