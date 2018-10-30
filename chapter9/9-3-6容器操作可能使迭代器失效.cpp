#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;
/*
在向容器添加元素之后
    如果容器是vector或string，且存储空间被重新分配，则指向容器的迭代器，指针，引用都会失效
    如果存储空间未重新分配，指向插入位置之前的迭代器，指针，引用都有效，之后都无效

    对于deque，插入到除了首尾位置之外的任何位置都会导致迭代器，指针，引用失效
    如果在首尾位置添加元素，迭代器会失效，但是指向存在元素的引用和指针不会失效

    对于list和forward_list，指向容器的迭代器（包括尾后，首前迭代器）、指针和引用都有效

在容器删除一个元素后
    对于list和forward_list，指向容器其他位置的迭代器（包括尾后，首前迭代器）、指针和引用都有效

    对于deque，如果在首尾之外的任何位置删除元素，那么指向被删除元素外其他元素的迭代器。引用或指针也会失效
    如果删除deque尾元素，则尾后迭代器也会失效但其他迭代器，指针，引用不受影响
    如果删除首元素，这些也不会受影响

    对于vector和string，指向被删除元素之前的迭代器，引用，指针都有效。
    注意：当我们删除元素时，尾后迭代器总是失效

*/
/*
编写改变容器的循环程序：必须考虑迭代器，引用，指针可能失效的问题。要保证每个循环步中都更新迭代器、引用或指针
如果循环中调用的是insert或erase，那么更新迭代器很容易
*/
int main()
{
//循环删除偶元素，复制奇元素
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
        {
            iter = vi.insert(iter,*iter);  //在iter位置之前插入一个*iter 返回新的元素的迭代器
            iter += 2;  //跳过新元素，和复制的元素
        }
        else
        {
            iter = vi.erase(iter);  //iter指向删除元素的后一个元素
        }
    }

    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;
    return 0;
}
