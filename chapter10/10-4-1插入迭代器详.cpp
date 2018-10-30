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


    //copy 函数  copy(InputIterator _First,InputIterator _Last,OutputIterator _DestBeg)
    //将迭代器[_First,_Last) 范围内的元素复制到 目标区间 _Destbeg的起始位置
    list<int> lst = {1,2,3,4};
    list<int> lst2,lst3;  //空list
    copy(lst.begin(),lst.end(),front_inserter(lst2));
    //调用front_inserter会得到一个迭代器,接下来会调用push_front,每个插入到容器c中时，都成为c的新首元素
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
