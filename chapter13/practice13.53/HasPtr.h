#ifndef HASPTR_H_INCLUDED
#define HASPTR_H_INCLUDED

#include <string>
#include <iostream>
class HasPtr
{
public:
    //默认构造函数
    HasPtr(const std::string& s = std::string()):ps(new std::string(s)),i(0){}
    //拷贝构造函数
    HasPtr(const HasPtr&);
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr &);
    //移动构造函数
    HasPtr(HasPtr &&)noexcept;
    //移动赋值运算符
    HasPtr& operator=(HasPtr &&)noexcept;

    ~HasPtr();

private:
    //释放内存
    void free();
    std::string *ps;
    int i;
};




#endif // HASPTR_H_INCLUDED
