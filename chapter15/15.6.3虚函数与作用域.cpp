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
    //隐藏了基类的fcn，这里的fcn不是虚函数
    //D1这个类只是简单的继承了Base::fcn()的定义
    int fcn(int i){cout<<"fcn(int) in D1 "<<i<<endl;}       //形参列表与Base中的fcn不一致
    virtual void f2(){cout<<"virtual f2 in D1"<<endl;}  //是一个新的虚函数，在Base中不存在
};

class D2:public D1
{
public:
    int fcn(int i){cout<<"fcn(int) in D2 "<<i<<endl;}  //D1中的函数不是虚函数，所以这里的该函数隐藏了D1::fcn(int)
    int fcn(){cout<<"virtual fcn in D2"<<endl;}  //覆盖了Base的虚函数fcn
    virtual void f2()override{cout<<"virtual f2 in D2"<<endl;}  //覆盖了D1中的虚函数f2
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
    pb->fcn();  //动态绑定，只是d1中没有对虚函数fcn重写，将fcn当做普通的函数被d1继承。
    pd1 = &d2;
    pd1->f2();
    pb = &d2;
    pb->fcn();  //派生类可以向间接基类发生动态转换
    cout<<endl;
    //通过基类调用隐藏的虚函数
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
    //bp2->f2();  //动态绑定，但是Base类没有定义f2函数
    d1p->f2();
    d2p->f2();
    cout<<endl;

    //对非虚函数的调用
    Base *p1 = &d2obj;
    D1 *p2 = &d2obj;
    D2 *p3 = &d2obj;
    //p1->fcn(42);  //因为int fcn(int) 函数不是虚函数，所以不会发生动态绑定，
    p2->fcn(42);    //实际调用的函数版本由指针的静态类型决定
    p3->fcn(42);




    return 0;
}
