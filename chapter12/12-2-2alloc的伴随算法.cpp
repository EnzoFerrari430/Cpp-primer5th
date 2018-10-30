#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
这些函数在给定目的位置创建元素，而不是由系统分配内存给它们
uninitialized_copy(b,e,b2)      从迭代器b和e指出的输入范围中拷贝元素到迭代器b2指定的未构造的原始内存中。b2指向的内存必须足够大，
                                能够容纳输入序列中元素的拷贝,返回一个尾后迭代器
uninitialized_copy_n(b,n,b2)    从迭代器b指向的元素开始，拷贝n个元素到b2开始的内存中

uninitialized_fill(b,e,t)       在迭代器b和e指定的原始内存范围中创建对象，对象的值均为t的拷贝

uninitialized_fill_n(b,n,t)     从迭代器b指向的内存地址开始创建n个对象。b必须指向足够大的未构造的原始内存，能够容纳给定数量的对象
                                返回一个尾后迭代器
*/
int main()
{
    allocator<int> alloc;
    vector<int> v1{1,2,3,4,5,6};
    auto p = alloc.allocate(v1.size() * 2);
    //通过拷贝v1中的元素来构造从p开始的元素
    auto q = uninitialized_copy(v1.begin(),v1.end(),p);
    //将剩余元素初始化为42
   uninitialized_fill_n(q,v1.size(),42);
    while(p != q+6)
    {
        cout<<*p<<" ";
        ++p;
    }
    cout<<endl;


    return 0;
}
