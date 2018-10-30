#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <typeinfo>
using namespace std;
using namespace std::placeholders;


/*
�������������������
    back_inserter       ����һ��ʹ��push_back�ĵ�����
    front_inserter      ����һ��ʹ��push_front�ĵ�����
    inserter            ����һ��ʹ��inserter�ĵ��������˺������ܵڶ����������������������һ��ָ����������ĵ�������
                        Ԫ�ؽ������뵽��������������ʾ��Ԫ��֮ǰ

     it��һ��������
    ����������Ĳ���    it = t,��itָ����λ�ò���ֵt�����ݲ���������Ĳ�ͬ����ֱ����push_back push_front��insert(t,p) pΪ���ݸ�inserter�ĵ�����λ��

*/

int main()
{
    vector<int> ival;
    auto it = back_inserter(ival);
    cout<<typeid(it).name()<<endl;
    for(int i = 0 ;i <10 ;++i)
    {
        it = i;
    }
    for(auto c: ival)
    {
        cout<<c<<' ';
    }



    return 0;
}
