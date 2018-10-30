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
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr) {}; //Ĭ�Ϲ��캯��
    StrVec(const StrVec&);  //�������캯��������һ�������á���������������ͣ�ֵ���ݵĻ���ʵ�δ����βξ�Ҫ����һ�ο������죬�����������ﶼ��û����ɿ������졣����γ���ì�ܡ�
    StrVec& operator=(const StrVec&);  //�������ʹ������  1.��ֹ��û�ж��忽�����캯��֮��ʹ��Ĭ�ϵĿ������캯����ɵ�δ֪Ӱ�졣2.ʵ�δ����βλ����һ�ο�������Ҫ����CPU�Ŀ���
    StrVec( std::initializer_list<std::string> il );
    ~StrVec();

    //����vector��һЩ�ӿں���
    std::string* begin()const
    {
        return elements;   //stl������
    }
    std::string* end()const
    {
        return first_free;
    }

    std::string at(size_t num);
    //!!!C++��const ���õ��Ƕ���ʱֻ�ܷ��ʸö����const ��������Ϊ���������п��ܻ��޸ĸö���ĳ�Ա��������Ϊ�˱���������鷢��������Ϊ���÷�const�����Ǵ���ġ�
    void push_back(const std::string&);
    size_t size() const
    {
        return first_free - elements;   //ע�⣡��:2��ͬ���ͣ�ָ��ͬһ�������ָ��������������������ָ����ֵ�ϵĲ���ǰ���������ָ��ָ�����͵Ĵ�С�Ľ����
    }
    size_t capacity() const
    {
        return cap - elements;   //��������
    }

    bool empty() const
    {
        return (first_free - elements)? false : true;    //�Ƿ�Ϊ�գ��ǿշ���true�����򷵻�false
    }

    void reserve( size_t new_cap );  //��������������n��Ԫ�ص��ڴ�ռ�

    void resize( size_t cnt, const std::string &s  );



private:

    std::allocator<std::string> alloc;  //����Ԫ��

    //4�����ߺ���
    void free();  //����Ԫ�أ����ͷ��ڴ�
    void reallocate();  //��ø�����ڴ沢�������е�Ԫ��
    //ȷ��StrVec����������һ����Ԫ�صĿռ�.���û�пռ������Ԫ�أ��ú�������reallocate���������Ŀռ�
    void chk_n_alloc()
    {
        if( size() == capacity() )
        {
            reallocate();
        }
    }

    //�����ڴ棬������һ��������Χ�е�Ԫ��,����1,2��ʾһ����Χ�е�Ԫ��
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);


    std::string* elements;
    std::string* first_free;
    std::string* cap;
};



#endif // STRVEC_H_INCLUDED
