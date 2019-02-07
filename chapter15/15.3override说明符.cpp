#include <iostream>
using namespace std;
/*
    ���������������һ��������������麯����������ͬ�����β��б�ͬ�������ǺϷ�����Ϊ��
    ����������Ϊ�¶������������������ԭ�еĺ����໥�����ġ���ʱ��������û�и��ǵ������еİ汾��

    ���������������ǳ���Ա�Լ�����д�����β��б�

    �������ִ���һ����ԱȽ��ѷ��֡�

    ��C++11�±�׼�У����ǿ���ʹ��override�ؼ�����˵���������е��麯����

    �����������������ͬʱ������Ҳ����Ϊ���Ƿ���һЩ����
*/

class B
{
public:
    virtual void f1(int)const;
    virtual void f2();
    void f3();
};

void B::f1(int a)const
{
    cout<<"virtual function f1 in Class B"<<endl;
}

void B::f2()
{
    cout<<"virtual function f2 in Class B"<<endl;
}

void B::f3()
{
    cout<<"normal function f3 in Class B"<<endl;
}

class D1 : public B
{
public:
    virtual void f1(int) const override;  //��ȷ��  f1������е�f1ƥ��  constҲҪ�ǵü���
    //virtual void f2(int)override;         //����  Bû������f2(int)�ĺ���
    //virtual void f3()override;            //����  f3�����麯��
    //virtual void f4()override;            //����  Bû����Ϊf4�ĺ���
};

void D1::f1(int a)const  //  !!!override���ⲿ����ʱ���ü�
{
    cout<<"virtual function f1 in Class D1"<<endl;
}

/*
    ���ǻ��ܰ�ĳ������ָ��Ϊfinal����������Ѿ��Ѻ��������final�ˣ���֮����κγ��Ը��Ǹú����Ĳ���������������
*/

class D2 : public B
{
public:
    //��B��̳�f2()��f3()����������f1(int)
    virtual void f2()override;  //���е��麯�������ж���
    virtual void f1(int)const final;  //����������������า��f1(int)

};

void D2::f1(int a)const
{
    cout<<"final virtual function f1 in Class D2"<<endl;
}

void D2::f2()
{
    cout<<"virtual function f2 in Class D2"<<endl;
}

/*
�麯����Ĭ��ʵ��
    �������ͨ����������û���ָ����ú�������ʹ�û����ж����Ĭ��ʵ�Ρ�
    ��ʹʵ�����е���������ĺ����汾�����������ຯ����Ĭ��ʵ�������ǻ��ඨ���Ĭ��ʵ��
*/

class Base
{
public:
    virtual void fun(int a = 10) const;  //ԭʼ���麯�����ü�override
};

void Base::fun(int a)const
{
    cout<<"virtual function fun in Class Base. And the number a is : "<<a<<endl;
}

class Derived : public Base
{
public:
    virtual void fun(int a = 20) const override;
};

void Derived::fun(int a)const
{
    cout<<"virtual function fun in Class Derived. And the number is : "<<a<<endl;
}

/*
�ر��麯������
    ��ĳЩ����£�����ϣ�����麯���ĵ��ò�Ҫ���ж�̬�󶨣�����ǿ����ִ���麯����ĳ���ض��汾
    ʹ�����������������ʵ����һĿ��
*/

int main()
{
    B b;
    D1 d1;
    b.f1(0);
    d1.f1(0);
    D2 d2;
    d2.f1(0);
    d2.f2();
    d2.f3();

    cout<<endl;
    cout<<endl;
    Base base;
    Derived derived;
    Base *pbase;
    pbase = &base;
    pbase->fun();
    pbase = &derived;  //�������ͨ����������û���ָ����ú�������ʹ�û����ж����Ĭ��ʵ�Ρ�
    pbase->fun();
    //�ر��麯������
    //����pbase�Ѿ�ָ����������derived
    pbase->Base::fun();


    return 0;
}
