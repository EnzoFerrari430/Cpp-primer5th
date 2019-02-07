#include <iostream>

using namespace std;
/*
    就像友元关系不能传递一样，友元关系同样也不能继承

    基类的友元在访问派生类成员时不具有特殊性，类似的，派生类的友元也不能随意访问基类的成员
*/
class Pal;

class Base
{
    friend class Pal;
protected:
    int prot_mem;  //protected成员
};

class Sneaky : public Base
{
    friend void clobber(Sneaky&);  //能访问Sneaky::prot_mem
    friend void clobber(Base&);  //不能访问Base::prot_mem
    int j;  //class 默认是private的
};

class Pal
{
public:
    int f(Base b){return b.prot_mem;}  //正确 Pal是Base的友元
    int f2(Sneaky s){return s.j;}  //错误，Pal不是Sneaky的友元

    //对基类的访问权限由基类本身控制，即使对于派生类的基类部分也是如此
    int f3(Sneaky s){return s.prot_mem;}  //正确，Pal是Base的友元
};

int main()
{


    return 0;
}
