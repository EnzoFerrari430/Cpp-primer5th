#include <iostream>
#include <string>
using namespace std;

/*
����typedef double A�����Ͳ���A�����ˣ����tmp����һ��double
*/
typedef double A;
template <typename A,typename B>
void f(A a,B b)
{
    A tmp = a;
    double B;  //��Ϊ���ǲ�������ģ�������������������������ΪB�ı����Ǵ����

    //cout<< a << " " << b <<endl;
}

//���ڲ������������ã�����һ��ģ���������һ���ض�ģ������б���ֻ�ܳ���һ��
//template <typename V,typename V>  //�����Ѿ�������һ����
//void f()
//{
//
//
//}

//�뺯��������ͬ�������е�ģ����������ֲ����붨���е���ͬ
template <typename T> T clac(const T&,const T&);

template <typename Type>
Type clac(const Type& lhs,const Type& rhs)
{
    cout<<"hello world"<<endl;
    return lhs;
}

int main()
{
    f(1,2);
    clac(1,2);


    return 0;
}
