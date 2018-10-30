#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A():a1(100),a2(200)
    {
        a1 = 1;
        a2 = 2;
        a3 = 3;
        a = 4;
    }
    void fun()
    {
        cout<<a<<endl;
        cout<<a1<<endl;
        cout<<a2<<endl;
        cout<<a3<<endl;
    }
    A add()
    {
        //成员函数通过一个名为this的额外隐式参数来访问调用它的那个对象
        ++a3;
        //return a3;
        return *this;
    }
public:
    int a1;
protected:
    int a2;
private:
    int a3;
};

int main()
{
    A itema;
    itema.a = 10;
    itema.a1 = 20;
    //itema.a2 = 30;  类外不能访问protected成员
    //itema.a3 = 40;  类外不能访问private成员
    itema.fun();
    A itemb = itema.add();
    itema.fun();
    itemb.fun();
    A itemc;
    itemc.fun();

    return 0;
}
