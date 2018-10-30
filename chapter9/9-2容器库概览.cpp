#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;
/*
容器操作
类型别名
    iterator            此容器类型的迭代器类型
    const_iterator      可以读取元素，但不能修改元素的迭代器类型
    size_type           无符号整数类型，足够保存此种容器类型最大可能容器的大小
    difference_type     带符号整数类型，足够保存两个迭代器之间的距离
    value_type          元素类型
    reference           元素的左值类型
    const_reference     元素的const左值类型

构造函数
    C c;                默认构造函数
    C c1(c2);           构造c2的拷贝c1
    C c(b,e);           构造c,将迭代器b和e指定的范围内的元素拷贝到c(array不支持)
    C c{a,b,c...};      列表初始化c

赋值与swap
    c1 = c2;
    c1 = {a,b,c...}
    a.swap(b)
    swap(a,b)

大小
    c.size()
    c.max_size()        c可保存的最大元素的数目
    c.empty()

添加删除元素(不适用于array)
    c.insert(args)      将args中的元素拷贝进c
    c.emplace(inits)    使用inits构造c中的一个元素
    c.erase(args)       删除args指定的元素
    c.clear()           删除c中所有的元素,返回void

关系运算符
    ==  !=
    <,<=,>,>=

获取迭代器
    c.begin(),c.end()
    c.cbegin(),c.cend() 返回const_iterator

反向容器的额外成员
    reverse_iterator    按逆序寻址元素的迭代器
    const_reverse_iterator  不能修改元素的逆序迭代器
    c.rbegin(),c.rend() 返回指向c的尾元素和首元素之前位置的迭代器
    c.crbegin(),c.crend()返回const_reverse_iterator
*/
int main()
{
//练习9.2
    list<deque<int>> li;

    return 0;
}
