#include "practice13.44String.h"
#include <algorithm>
#include <iostream>

//用be表示的范围初始化一段字符串
std::pair<char*,char*> String::alloc_n_copy(char *b,char *e)
{
    //data指针指向alloc申请的内存块首地址
    auto data = alloc.allocate( e - b );
    //uninitialized_copy函数用b，e表示的范围初始化data为首的内存地址，返回尾后迭代器  return {}  initialized_list来构造返回类型
    return {data,uninitialized_copy(b,e,data)}
}

void String::range_initializer(const char *first,const char *last)
{
    auto newstr = alloc_n_copy(first,last);
    elements = newstr.first;
    first_free = newstr.second;
}

//这个想法太厉害了
String::String(const char *p)
{
    //const_cast只能转换底层const，将常量对象转换为非常量对象(去const性质),这样编译器不会阻止我们对该对象进行写操作
    char *p1 = const_cast<char*>(p);
    while(*p1)
    {
        ++p1;  //退出时p1指向尾后元素
    }
    range_initializer(p,p1);
}

String::String(const String& rhs)
{
    range_initializer(rhs.elements,rhs.first_free);
    std::cout<<"copy construct"<<std::endl;
}

void String::free()
{
    size_t n = first_free - elements;
    while(first_free > elements)
    {
        alloc.destroy(--first_free);
    }
    alloc.deallocate(elements,n);

    //参考答案
//    if(elements)
//    {
//
//        for_each(elements,first_free,[this](char &c){alloc.destroy(&c);});
//        alloc.deallocate(elements,first_free-elements);
//    }

}

String& String::operator=(const String& rhs)
{
    //range_initializer(rhs.elements,rhs.first_free);  不能直接这样，要先释放原来的内存
    auto newstr = alloc_n_copy(rhs.elements,rhs.first_free);
    free();
    elements = newstr.first;
    first_free = newstr.second;
    std::cout<<"copy-assignment"<<std::endl;
    return *this;
}
