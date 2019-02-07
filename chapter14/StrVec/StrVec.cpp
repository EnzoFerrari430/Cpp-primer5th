#include "StrVec.h"

//practice14.16  ������ָ������жϣ���ָ��ָ�����������ж�
bool operator==(const StrVec &lhs,const StrVec &rhs)
{
    if( lhs.size() != rhs.size() )
    {
        return false;
    }
    for(auto itr1 = lhs.begin() ,itr2 = rhs.begin() ; itr1 != lhs.end() && itr2 != rhs.end() ; ++itr1, ++itr2 )
    {
        if( *itr1 != *itr2 )
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const StrVec &lhs,const StrVec &rhs)
{
    return !(lhs == rhs);
}

//practice14.18
bool operator<(const StrVec &lhs,const StrVec &rhs)
{
    return std::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
}

bool operator>(const StrVec &lhs,const StrVec &rhs)
{
    return rhs<lhs;
}

bool operator<=(const StrVec &lhs,const StrVec &rhs)
{
    return !(lhs>rhs);
}

bool operator>=(const StrVec &lhs,const StrVec &rhs)
{
    return !(lhs<rhs);
}

//14.4��ֵ�����practice14.23
StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
    //�β���std::initializer_list<std::string> il  ������������������ֵ���
    auto data = alloc_n_copy(il.begin(),il.end());
    free();  //�ͷ�֮ǰ���ڴ�ռ�
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::push_back(const std::string& s )
{
    chk_n_alloc();  //ȷ���пռ������µ�Ԫ��

    //��first_freeָ���Ԫ���й���s�ĸ���
    alloc.construct(first_free++,s);
}

//�ڿ������߸�ֵStrVecʱʹ�øú������ú�������һ��ָ���pair��2��ָ��ֱ�ָ���¿ռ�Ŀ�ʼλ�úͿ�����β��λ��
std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string* b,const std::string* e)
{
    //data��ָ�룬ָ��alloc�����ԭʼ�ռ���׵�ַ
    auto data = alloc.allocate(e - b);

    //���Է��ػ������б�������ʱ�����г�ʼ��������һ���ڴ�ռ���׵�ַ����������һ����������b��e��ʾ��һ����Χ����ʼ��dataΪ�׵��ڴ��ַ������β����������������stringָ��
    return {data,uninitialized_copy(b,e,data)};
}

//free�����Ĺ��ܣ�1.destroyԪ�� 2.�ͷ�StrVec�Լ�������ڴ�ռ�
void StrVec::free()
{
    //���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ�գ�����ʲôҲ����
    if(elements)
    {
        //��������Ԫ��
        for(auto p = first_free; p!= elements;)
        {
            //destroy��pָ���Ԫ�ؽ�����������
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap - elements);
    }
}



//�������캯��
StrVec::StrVec(const StrVec& s)
{
    //����alloc_n_copy����ռ���������s��һ�����Ԫ��
    //newdata��������pair<string*,string*>
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

//�ƶ����캯��
StrVec::StrVec(StrVec &&s) noexcept
{
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    s.elements = s.first_free = s.cap = nullptr;
}

//�ƶ���ֵ�����
StrVec& StrVec::operator=(StrVec &&s) noexcept
{
    //�ж��Ը�ֵ
    if( this != &s )
    {
        //�ͷ��Լ�ԭ�ȿռ�
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    elements = first_free = cap = nullptr;

    for(auto it = il.begin() ; it != il.end() ; ++it)
    {
        chk_n_alloc();
        alloc.construct(first_free++,*it);
    }
}


std::string StrVec::at(size_t num)
{
    size_t i = 0;
    while(i < num)
    {
        ++i;
    }
    return *(elements + i);  //����Ҫ������飬��ֹnum���󣬳���first_free����cap������2�ִ���ķ�ʽ
}


//��������
StrVec::~StrVec()
{
    free();
}


StrVec& StrVec::operator=(const StrVec& rhs)
{
    //�Ƚ����ݿ�������,��ô���ĺô��ǿ��Դ����Լ����Լ���ֵ�������
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}


void StrVec::reallocate()
{
    //���䵱ǰ2����С���ڴ�ռ�
    auto newcapacity = size()? 2*size() : 1;
    //�����µ��ڴ�
    auto newdata = alloc.allocate(newcapacity);  //newdataָ��������ݿռ��׵�ַ

    auto dest = newdata;   //ָ������������һ������λ��
    auto elem = elements;  //ָ�����������һ��Ԫ��

    for(size_t i = 0; i!= size() ; ++i)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();  //���Ԫ���ƶ����ͷž��ڴ�ռ�
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;


}


void StrVec::reserve(size_t new_cap)
{
    if( new_cap <= capacity() )
    {
        return ;
    }
    auto newdata = alloc.allocate(new_cap);

    auto dest = newdata;
    auto elem = elements;

    for(size_t i = 0 ; i != size() ; ++i)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::resize( size_t cnt,const std::string& s )
{
    if( cnt < size() )
    {
        while(first_free != elements + cnt)
        {
            alloc.destroy(--first_free);
        }
    }
    else if( cnt > size() )
    {
        while( cnt > capacity() )
        {
            reallocate();
        }
        for( size_t i = size() ; i != cnt ; ++i  )
        {
            alloc.construct(first_free++,s);
        }
    }
}