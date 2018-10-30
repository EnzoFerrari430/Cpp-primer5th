#ifndef STRVEC_H_INCLUDED
#define STRVEC_H_INCLUDED


#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <utility>
#include <initializer_list>
class StrVec
{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr) {}; //默认构造函数
    StrVec(const StrVec&);  //拷贝构造函数，参数一定是引用。如果不是引用类型，值传递的话。实参传进形参就要进行一次拷贝构造，但是我们这里都还没有完成拷贝构造。这就形成了矛盾。
    StrVec& operator=(const StrVec&);  //这里参数使用引用  1.防止类没有定义拷贝构造函数之后，使用默认的拷贝构造函数造成的未知影响。2.实参传进形参会进行一次拷贝，需要花费CPU的开销
    StrVec( std::initializer_list<std::string> il );
    ~StrVec();

    //类型vector的一些接口函数
    std::string* begin()const
    {
        return elements;   //stl的特性
    }
    std::string* end()const
    {
        return first_free;
    }

    std::string at(size_t num);
    //!!!C++中const 引用的是对象时只能访问该对象的const 函数，因为其他函数有可能会修改该对象的成员，编译器为了避免该类事情发生，会认为调用非const函数是错误的。
    void push_back(const std::string&);
    size_t size() const
    {
        return first_free - elements;   //注意！！:2个同类型，指向同一个数组的指针相减，结果并不是两个指针数值上的差，而是把这个差除以指针指向类型的大小的结果。
    }
    size_t capacity() const
    {
        return cap - elements;   //返回容量
    }

    bool empty() const
    {
        return (first_free - elements)? false : true;    //是否为空，是空返回true，否则返回false
    }

    void reserve( size_t new_cap );  //分配至少能容纳n个元素的内存空间

    void resize( size_t cnt, const std::string &s  );



private:

    std::allocator<std::string> alloc;  //分配元素

    //4个工具函数
    void free();  //销毁元素，并释放内存
    void reallocate();  //获得更多的内存并拷贝已有的元素
    //确保StrVec至少有容纳一个新元素的空间.如果没有空间添加新元素，该函数调用reallocate来分配更多的空间
    void chk_n_alloc()
    {
        if( size() == capacity() )
        {
            reallocate();
        }
    }

    //分配内存，并拷贝一个给定范围中的元素,参数1,2表示一个范围中的元素
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);


    std::string* elements;
    std::string* first_free;
    std::string* cap;
};



#endif // STRVEC_H_INCLUDED
