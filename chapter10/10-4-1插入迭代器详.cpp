#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <list>
using namespace std;
int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    for(auto c: vi)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    auto it = inserter(vi,vi.begin() + 3);
    *it = 123;
    for(auto c: vi)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    //copy ����  copy(InputIterator _First,InputIterator _Last,OutputIterator _DestBeg)
    //��������[_First,_Last) ��Χ�ڵ�Ԫ�ظ��Ƶ� Ŀ������ _Destbeg����ʼλ��
    list<int> lst = {1,2,3,4};
    list<int> lst2,lst3;  //��list
    copy(lst.begin(),lst.end(),front_inserter(lst2));
    //����front_inserter��õ�һ��������,�����������push_front,ÿ�����뵽����c��ʱ������Ϊc������Ԫ��
    for(auto c: lst2)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    copy(lst.begin(),lst.end(),inserter(lst3,lst3.begin()));
    for(auto c: lst3)
    {
        cout<<c<<' ';
    }
    cout<<endl;





    return 0;
}
