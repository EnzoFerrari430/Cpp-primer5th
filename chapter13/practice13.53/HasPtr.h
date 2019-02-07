#ifndef HASPTR_H_INCLUDED
#define HASPTR_H_INCLUDED

#include <string>
#include <iostream>
class HasPtr
{
public:
    //Ĭ�Ϲ��캯��
    HasPtr(const std::string& s = std::string()):ps(new std::string(s)),i(0){}
    //�������캯��
    HasPtr(const HasPtr&);
    //������ֵ�����
    HasPtr& operator=(const HasPtr &);
    //�ƶ����캯��
    HasPtr(HasPtr &&)noexcept;
    //�ƶ���ֵ�����
    HasPtr& operator=(HasPtr &&)noexcept;

    ~HasPtr();

private:
    //�ͷ��ڴ�
    void free();
    std::string *ps;
    int i;
};




#endif // HASPTR_H_INCLUDED
