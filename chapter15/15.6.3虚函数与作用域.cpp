#include <iostream>
using namespace std;

class Base
{
public:
    virtual int fcn(){cout<<"virtual fcn in Base"<<endl;}
};

class D1: public Base
{
public:
    //�����˻����fcn�������fcn�����麯��
    //D1�����ֻ�Ǽ򵥵ļ̳���Base::fcn()�Ķ���
    int fcn(int i){cout<<"fcn(int) in D1 "<<i<<endl;}       //�β��б���Base�е�fcn��һ��
    virtual void f2(){cout<<"virtual f2 in D1"<<endl;}  //��һ���µ��麯������Base�в�����
};

class D2:public D1
{
public:
    int fcn(int i){cout<<"fcn(int) in D2 "<<i<<endl;}  //D1�еĺ��������麯������������ĸú���������D1::fcn(int)
    int fcn(){cout<<"virtual fcn in D2"<<endl;}  //������Base���麯��fcn
    virtual void f2()override{cout<<"virtual f2 in D2"<<endl;}  //������D1�е��麯��f2
};

int main()
{
    Base *pb;
    D1 *pd1;
    D2 *pd2;
    D1 d1;
    d1.fcn(1);
    D2 d2;
    d2.fcn();
    pb = &d1;
    pb->fcn();  //��̬�󶨣�ֻ��d1��û�ж��麯��fcn��д����fcn������ͨ�ĺ�����d1�̳С�
    pd1 = &d2;
    pd1->f2();
    pb = &d2;
    pb->fcn();  //������������ӻ��෢����̬ת��
    cout<<endl;
    //ͨ������������ص��麯��
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();
    cout<<endl;
    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    //bp2->f2();  //��̬�󶨣�����Base��û�ж���f2����
    d1p->f2();
    d2p->f2();
    cout<<endl;

    //�Է��麯���ĵ���
    Base *p1 = &d2obj;
    D1 *p2 = &d2obj;
    D2 *p3 = &d2obj;
    //p1->fcn(42);  //��Ϊint fcn(int) ���������麯�������Բ��ᷢ����̬�󶨣�
    p2->fcn(42);    //ʵ�ʵ��õĺ����汾��ָ��ľ�̬���;���
    p3->fcn(42);




    return 0;
}
