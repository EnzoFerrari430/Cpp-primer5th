#include "HasPtr.h"

void HasPtr::free()
{
    delete ps;
    ps = nullptr;
    i = 0;
}

//拷贝构造函数
HasPtr::HasPtr(const HasPtr& rhs)
{
    ps = new std::string( *rhs.ps );
    i = rhs.i;
    std::cout<<"copy construct"<<std::endl;
}

//拷贝赋值运算符
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    free();
    ps = new std::string(*rhs.ps);
    i = rhs.i;
    std::cout<<"copy assignment"<<std::endl;
    return *this;
}

//移动构造函数
HasPtr::HasPtr(HasPtr &&rhs)noexcept
{
    ps = rhs.ps;
    i = rhs.i;
    rhs.ps = nullptr;  //让rhs处于一种安全的状态
    std::cout<<"move construct"<<std::endl;
}

//移动赋值运算符
HasPtr& HasPtr::operator=(HasPtr &&rhs)noexcept
{
    //先排除自赋值情况
    if( this != &rhs )
    {
        free();
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }

    std::cout<<"move assignment"<<std::endl;
    return *this;
}

HasPtr::~HasPtr()
{
    std::cout<<"deconstruct"<<std::endl;
    free();
}
