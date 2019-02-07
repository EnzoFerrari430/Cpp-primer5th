#include <iostream>
using namespace std;

class Base
{
public:
    void pub_mem(){cout<<"pub_mem() Base"<<endl;}  //public��Ա
protected:
    int prot_mem;  //protected��Ա
private:
    char priv_mem;  //private��Ա
};

class Pub_Derv : public Base
{
public:
    void memfcn(Base &b){b = *this;}
    //��ȷ�� �������ܷ���protected��Ա
    int f(){return prot_mem;}
    //���� private��Ա������������˵�ǲ��ɷ��ʵ�
    //char g(){return priv_mem;}
};

class Prot_Derv : protected Base
{
public:
    void memfcn(Base &b){b = *this;}
    int f2()const {return prot_mem;}
};

class Priv_Derv : private Base
{
public:
    void memfcn(Base &b){b = *this;}
    //private  ��Ӱ��������ķ���Ȩ��
    int f1() const {return prot_mem;}

    //pub_mem()�ܱ��̳У�Ҳ�ܱ����ã���������˵����ָʾ�ú�����������private�ģ��൱�������д��
/*
private:
    Base2::pub_mem();
*/
};

/*
    ��������˵���������Կ��Ƽ̳��������������ķ���Ȩ��
*/
class Derived_from_Public : public Pub_Derv
{
public:
    void memfcn(Base &b){b = *this;}
    //��ȷ�� Base::prot_mem��Pub_Derv������protected��
    int use_base(){return prot_mem;}
};

class Derived_from_Protected : public Prot_Derv
{
public:
    void memfcn(Base &b){b = *this;}
    //���� Base::prot_mem��Priv_Derv�е�private��
    //int use_base(){return prot_mem;}
};

class Derived_from_Private : public Priv_Derv
{
public:
    //practice15.19  �������,�����Ķ����Է���  Priv_Derv��private�������ģ���Priv_Derv���е�Base��Ա����private�ģ������಻�ܷ��ʻ����˽�г�Ա
    //void memfcn(Base &b){b = *this;}

    //���� Base::prot_mem��Priv_Derv�е�private��
    //int use_base(){return prot_mem;}
};


int main()
{
    Pub_Derv d1;
    Base *p = &d1;  //d1��������Pub_Derv
    //��ȷ

    Priv_Derv d2;
    //p = &d2;  //d2��������Priv_Derv
    //����ȷ

    Prot_Derv d3;
    //p = &d3;  //d3��������Prot_Derv
    //����ȷ

    Derived_from_Public dd1;
    p = &dd1;  //dd1��������Derived_from_Public
    //��ȷ

    Derived_from_Private dd2;
    //p = &dd2;  //dd2��������Derived_from_Private
    //����ȷ

    Derived_from_Protected dd3;
    //p = &dd3;  //dd3��������Derived_from_Protected
    //����ȷ

    //����544ҳ��ȷָ����ֻ�е������๫�еļ̳��Ի���ʱ���û��������ʹ��������������ת��

    return 0;
}
