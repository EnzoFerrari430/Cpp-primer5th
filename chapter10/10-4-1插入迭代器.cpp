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
插入迭代器的三种类型
    back_inserter       创建一个使用push_back的迭代器
    front_inserter      创建一个使用push_front的迭代器
    inserter            创建一个使用inserter的迭代器。此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。
                        元素将被插入到给定迭代器所表示的元素之前

     it是一个插入器
    插入迭代器的操作    it = t,在it指定的位置插入值t，根据插入迭代器的不同种类分别调用push_back push_front或insert(t,p) p为传递给inserter的迭代器位置

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
