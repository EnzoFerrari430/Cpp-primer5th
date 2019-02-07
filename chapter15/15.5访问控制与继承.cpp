#include <iostream>
using namespace std;
/*
������ĳ�Ա����Ԫֻ��ͨ����������������ʻ�����ܱ�����Ա
���������һ����������е��ܱ�����Աû���κη�����Ȩ
*/
class Base
{
protected:
    int prot_mem;  //protected��Ա
};

class Sneaky : public Base
{
    friend void clobber(Sneaky&);  //�ܷ���Sneaky::prot_mem
    friend void clobber(Base&);  //���ܷ���Base::prot_mem
    int j;  //class Ĭ����private��
};

void clobber(Sneaky &s){s.j = s.prot_mem = 0;}  //��ͨ����������ʻ���

//void clobber(Base &b){b.prot_mem = 0;}  //Base::prot_mem��protected  ����ֱ�ӷ��ʻ���
//������ĳ�Ա����Ԫֻ��ͨ������������������������л��ಿ�ֵ��ܱ�����Ա��������ֱ�ӶԻ�������еĳ�Ա���з���




/*
��Լ̳ж����ĳ�Ա�ķ���Ȩ��Ӱ�����أ�
    1.�����иó�Ա�ķ���˵����
    2.������������б��еķ���˵����
*/

class Base2
{
public:
    void pub_mem(){cout<<"pub_mem() Base2"<<endl;}  //public��Ա
protected:
    int prot_mem;  //protected��Ա
private:
    char priv_mem;  //private��Ա
};

class Pub_Derv : public Base2
{
public:
    //��ȷ�� �������ܷ���protected��Ա
    int f(){return prot_mem;}
    //���� private��Ա������������˵�ǲ��ɷ��ʵ�
    //char g(){return priv_mem;}
};

class Prot_Derv : protected Base2
{
public:
    int f2()const {return prot_mem;}
};

class Priv_Derv : private Base2
{
public:
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
    //��ȷ�� Base::prot_mem��Pub_Derv������protected��
    int use_base(){return prot_mem;}
};

class Derived_from_Private : public Priv_Derv
{
    //���� Base::prot_mem��Priv_Derv�е�private��
    //int use_base(){return prot_mem;}
};

int main()
{
    //��������˵������Ŀ���ǿ����������û�����������������������ڣ����ڻ����Ա�ķ���Ȩ��
    //˵���˾���d2�л��ಿ�ֵķ��ʶ���private�ģ�d1�л��ಿ�ֵķ��ʶ���public��
    Pub_Derv d1;  //�̳���Base��Ա��public��
    Priv_Derv d2; //�̳���Base�ĳ�Ա��private��

    d1.pub_mem();  //��ȷ�� pub_mem������������public��
    //d2.pub_mem();  //���� pub_mem������������private��     ˽�г�Ա����ֱ�ӵ���
    Prot_Derv d3;
    //d3.pub_mem();  //�൱���ⲿ�û�ֱ�ӵ�������ܱ����ĳ�Ա
    return 0;
}
