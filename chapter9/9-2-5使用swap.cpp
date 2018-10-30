#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
/*
    除了array外，交换2个容器内容的操作保证会很快，元素本身并未交换，swap只是交换了2个容器的内部数据结构
    除了array外，swap不对任何元素进行拷贝、删除或者插入操作，因此可以保证在常数时间内完成


    除了string外，指向容器的迭代器、引用、和指针在swap操作后都不会失效。它们然仍指向swap操作之前所指的那些元素。但是在只是容器变了
    对一个string调用swap会导致迭代器。引用和指针失效（相当于交换2个容器）

    与其他容器不同，swap2个array会真正交换它们的元素的值。因此，交换2个array所需的时间与array中元素的数目成正比（相当于交换array元素中的值）

*/
int main()
{


    return 0;
}
