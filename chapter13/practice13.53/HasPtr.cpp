#include "HasPtr.h"

void HasPtr::free()
{
    delete ps;
    ps = nullptr;
    i = 0;
}

//�������캯��
HasPtr::HasPtr(const HasPtr& rhs)
{
    ps = new std::string( *rhs.ps );
    i = rhs.i;
    std::cout<<"copy construct"<<std::endl;
}

//������ֵ�����
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    free();
    ps = new std::string(*rhs.ps);
    i = rhs.i;
    std::cout<<"copy assignment"<<std::endl;
    return *this;
}

//�ƶ����캯��
HasPtr::HasPtr(HasPtr &&rhs)noexcept
{
    ps = rhs.ps;
    i = rhs.i;
    rhs.ps = nullptr;  //��rhs����һ�ְ�ȫ��״̬
    std::cout<<"move construct"<<std::endl;
}

//�ƶ���ֵ�����
HasPtr& HasPtr::operator=(HasPtr &&rhs)noexcept
{
    //���ų��Ը�ֵ���
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
