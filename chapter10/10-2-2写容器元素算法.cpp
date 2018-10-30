#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
    一些算法将新值赋予序列中的元素。当我们使用这类算法时，必须注意确保序列原大小至少不小于我们要求算法写入的数目
    当填充的范围超过容器的大小，则会报错

    fill(iterator,iterator,val);  左闭右开
    fill_n(iterator,size,val);
*/
int main()
{
    vector<int> vec{31,654,318,8964,31,549,8,32414};
    fill(vec.begin(),vec.begin() + 5,9);  //  写入的大小 <= 容器元素的大小
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
    //不能在空容器上调用类似的写元素算法
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
