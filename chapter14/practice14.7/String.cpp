#include "String.h"
#include <algorithm>
#include <iostream>

//��be��ʾ�ķ�Χ��ʼ��һ���ַ���
std::pair<char*,char*> String::alloc_n_copy(const char *b,const char *e)
{
    //dataָ��ָ��alloc������ڴ���׵�ַ
    auto data = alloc.allocate( e - b );
    //uninitialized_copy������b��e��ʾ�ķ�Χ��ʼ��dataΪ�׵��ڴ��ַ������β�������  return {}  initialized_list�����췵������
    return {data,std::uninitialized_copy(b,e,data)};
}

void String::range_initializer(const char *first,const char *last)
{
    auto newstr = alloc_n_copy(first,last);
    elements = newstr.first;
    first_free = newstr.second;
}

//����뷨̫������
String::String(const char *p)
{
    //const_castֻ��ת���ײ�const������������ת��Ϊ�ǳ�������(ȥconst����),����������������ֹ���ǶԸö������д����
    char *p1 = const_cast<char*>(p);
    while(*p1)
    {
        ++p1;  //�˳�ʱp1ָ��β��Ԫ��
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

    //�ο���
//    if(elements)
//    {
//
//        for_each(elements,first_free,[this](char &c){alloc.destroy(&c);});
//        alloc.deallocate(elements,first_free-elements);
//    }

}

String::~String()
{
    free();
}

String& String::operator=(const String& rhs)
{
    //range_initializer(rhs.elements,rhs.first_free);  ����ֱ��������Ҫ���ͷ�ԭ�����ڴ�
    auto newstr = alloc_n_copy(rhs.elements,rhs.first_free);
    free();
    elements = newstr.first;
    first_free = newstr.second;
    std::cout<<"copy-assignment"<<std::endl;
    return *this;
}

//14.7
std::ostream& operator<<(std::ostream& output,const String &rhs)
{
    char *c = const_cast<char*>(rhs.c_str());
    while(*c)
    {
        output<<*c++;  //  ++��������ȼ�����*

    }
    return output;


}
