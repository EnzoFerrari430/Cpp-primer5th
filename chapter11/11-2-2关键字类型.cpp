#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/*
有序容器--map, multimap, set,multiset的关键字类型 必须定义元素的比较方法.
    默认情况下，标准库使用关键字类型的< 运算符来比较两个关键字。
    集合类型中，关键字就是元素类型；
    映射类型中，关键字类型就是元素第一部分的类型

可以提供自己定义的操作来代替关键字上的<运算符.
所提供的操作必须在关键字类型上定义一个严格弱序。严格弱序必须具备如下基本性质
    1.2个关键字不能同时“小于等于”对方:如果k1<=k2，那么k2就不能<=k1
    2.如果k1<=k2,且k2<=k3,那么k1<=k3
    3.如果k1,k2都不“小于等于”对方。那么k1,k2是等价的。如果k1等价于k2，k2等价于k1，那么k1等价于k3

为了指定使用自定义的操作，必须在定义关联容器类型时提供此操作的类型。如前所示，用尖括号指出要定义哪种类型的容器，
自定义的操作类型必须在尖括号中紧跟着元素类型给出。

定义multiset时必须提供2个类型：关键字类型和比较操作类型...Sales_data的比较操作类型应该是一种指针，可以指向compareIsbn
//bookstore中多条记录可以有相同的ISBN
//bookstore中的元素以ISBN的顺序进行排列
multiset<Sales_data, dectype(compareIsbn)*> bookstore(compareIsbn)
当我们向bookstore添加元素时，通过调用compareIsbn来为这些元素排序

*/
int main()
{


    return 0;
}
