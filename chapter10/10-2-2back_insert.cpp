#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;
/*
    插入迭代器是一种向容器中添加元素的迭代器
    当我们通过一个迭代器向容器元素赋值时，值被赋予迭代器指向的元素。
    而当我们通过插入迭代器赋值时，一个与赋值号右侧值相等的元素被添加到容器中。


    back_inserter接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器。
    通过此迭代器赋值时，赋值运算符会调用push_back将一个具有定值的元素添加到容器中
*/
int main()
{
    /*
    vector<int> vec;  //空向量
    auto it = back_inserter(vec);  //  返回一个与该容器绑定的插入迭代器，通过它赋值会将元素添加到vec中去
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
