#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
标准库中的顺序容器
vector          可变大小的数组.支持快速随机访问。在尾部之外的位置插入或删除元素可能会慢
deque           双端队列。支持快速随机访问。在头尾位置插入删除的速度很快
list            双向链表。只支持双向顺序访问。在list中任何位置进行插入删除操作速度都很快
forward_list    单向链表。只支持单向顺序访问。在链表任何位置进行插入删除速度都很快
array           固定大小数组。支持快读随机访问。不能添加删除元素
string          与vector相似的容器，但专门用于保存字符。随机访问快。在尾部插入删除速度快



练习9.1
a.list
b.deque
c.vector

*/

int main()
{

    vector<int> ival;
    cout<<ival.max_size()<<endl;


    return 0;
}
