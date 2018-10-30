#include <iostream>
#include <string>
using namespace std;

/*
类的行为像一个值，意味着它应该有自己的状态，当我们拷贝一个值的对象时，副本和原对象是完全独立的。改变副本不会对原对象有任何影响，反之亦然

行为像指针的类则共享状态，当我们拷贝一个这个类的对象时，副本和原对象使用相同的底层数据。改变副本也会改变原对象，反之亦然
*/


class HasPtr
{
public:
    HasPtr(const std::string &s = std::string() ):ps(new std::string(s)),i(0){}

    //合成的拷贝构造函数是浅拷贝
    //需要自己重写拷贝构造函数
    HasPtr(const HasPtr&);

    HasPtr& operator=(const std::string &s);

    ~HasPtr(){ delete ps; }

public:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& rhs)
{
    i = rhs.i;
    ps = new string(*rhs.ps);  //自己申请一块内存地址，拔rhs的ps指针指向的内容拷贝都这块内存中
}

HasPtr& HasPtr::operator=(const std::string &s)
{


    return *this;
}

//如果是浅拷贝( 合成的拷贝构造函数 )，会造成问题
HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;  //拷贝给定的HasPtr
    //处理ret

    return ret;  //ret和hp被销毁
    //ret和hp的ps成员指针指向同一块内存地址，f返回时，ret和hp被销毁，ps指针会被销毁2次，

    //此代码会被delete2次，将要发生什么是未定义的（个人理解:ps指向的内存的内容在第一次销毁时被释放，第二次销毁就是一个未定义的行为）
}

int main()
{
    HasPtr p("some values");
    f(p);  //  !!合成的拷贝构造函数是浅拷贝，可怕
    HasPtr q(p);  //现在p和q都指向无效的内存

    cout<<*q.ps<<endl;

    return 0;
}
