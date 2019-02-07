#include <iostream>
using namespace std;
class Base
{
public:
    Base() = default;
    Base(int a,int b):a(a),b(b){}
    virtual void fun()
    {
        cout<<"Base version ";
        cout<<"a: "<<a<<" b: "<<b<<endl;
    }

    int b = 0;
private:
    int a = 0;


};

class Derived : public Base
{
public:
    Derived() = default;
    Derived(int a,int b,int c):Base(a,b),c(c){}
//    virtual void fun()
//    {
//        cout<<"a: "<<a<<" b: "<<b<<" c: "<<endl;
//    }
    virtual void fun() override
    {
        cout<<"Derived version ";
        cout<<"b: "<<b<<" c: "<<c<<endl;
    }


protected:
    int c = 0;


};

int main()
{
    Base b;
    b.fun();

    Derived d(1,2,3);  //可以对基类的私有成员赋值，但是不能访问
    d.fun();
    Base *p = &d;
    p->fun();

    return 0;
}
