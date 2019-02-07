#include <iostream>
using namespace std;

/*
    和其他作用域一样，派生类也能重新定义在其直接基类或间接基类中的名字。
    此时派生类（内层作用域）的名字将隐藏定义在基类（外层作用域）的名字。
*/
class Base
{
public:
    Base() : mem(0){}
protected:
    int mem;
};

class Derived : public Base
{
public:
    Derived(int i):mem(i){}
    int get_mem()const{return mem;}
    int get_base_mem()const{return Base::mem;}  //可以通过作用域运算符来使用一个被隐藏的基类成员
protected:
    int mem;  //隐藏基类中的mem
};

int main()
{
    Derived d(42);
    cout<<d.get_mem()<<endl;

    //作用域运算符将覆盖掉原有的查找规则，并指示编译器从Base类的作用域开始查找mem
    cout<<d.get_base_mem()<<endl;

    return 0;
}
