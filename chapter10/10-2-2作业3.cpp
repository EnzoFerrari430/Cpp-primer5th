#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
int main()
{
    vector<int> vec;
    vec.reserve(10);
    //fill_n(vec.begin(),10,0);  没有错，但是没有任何意义
    fill_n(back_inserter(vec),10,0);
    for(auto c: vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    //10.8  back_inserter只是产生了一个插入迭代器,然后用这个插入迭代器进行插入操作
    return 0;
}
