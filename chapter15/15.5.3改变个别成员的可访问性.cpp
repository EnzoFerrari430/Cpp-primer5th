#include <iostream>
using namespace std;

/*
    ��ʱ���ǿ���ͨ��using�����ı�������̳е�ĳ�����ֵķ��ʼ���

*/

class Base
{
public:
    std::size_t size()const{return n;}
protected:
    std::size_t n;
};

class Derived : private Base  //ע�⣬private�̳�
{
public:
    //���ֶ���ߴ���صĳ�Ա�ķ��ʼ���
    using Base::size;  //���̳�����size()  ������public
protected:
    using Base::n;  //���̳ж�����n  ������protected
};
//  ������������ֻ��Ϊ��Щ���ɷ��ʵ������ṩ����

int main()
{


    return 0;
}
