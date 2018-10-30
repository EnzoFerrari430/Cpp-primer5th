#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}  //一定不能使用默认的拷贝构造函数

    HasPtr& operator=(const HasPtr&);
    ~HasPtr(){delete ps;}
public:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;  //先释放原先那块内存,切记切记,
    //★★如果rhs和*this是同一个对象，我们就将从已释放的内存中拷贝数据。所以要先拷贝到临时变量中去
    ps = newp;  //从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;
}

HasPtr f(HasPtr pos)
{
    auto p = pos;

    return p;
}

int main()
{
    HasPtr a("hello world");
    cout<<*a.ps<<endl;
    HasPtr b = f(a);
    cout<<*a.ps<<endl;
    cout<<*b.ps<<endl;
    return 0;
}

//13.24如果未定义析构函数，则申请的内存无法被释放。会造成内存泄漏，
//如果未定义拷贝构造函数，则拷贝是浅拷贝。一个类修改了ps，另一个类的内容也会改变。如果一个类释放了内存，则另一个类的ps会成为空悬指针
