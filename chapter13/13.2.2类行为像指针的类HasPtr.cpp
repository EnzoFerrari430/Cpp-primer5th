#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    //构造函数初始化引用为1  //s默认为空
    HasPtr(const string& s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    //拷贝构造函数
    HasPtr(const HasPtr &rhs);
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr &rhs);
    HasPtr& operator=(const string &rhs);
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;  //引用计数,这里使用指针，为了统一管理，共享计数
};

HasPtr::HasPtr(const HasPtr &rhs)
{
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    ++(*use);  //引用计数加1
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    --(*use);
    if( (*use) == 0 )
    {
        delete ps;
        ps = nullptr;
    }
    ps = rhs.ps;
    ++*rhs.use;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

HasPtr::~HasPtr()
{
    --(*use);
    if( (*use) == 0 )
    {
        delete ps;
        delete use;  //释放引用计数
        ps = nullptr;
    }
}

int main()
{
    HasPtr h1("hi mom!");
    HasPtr h2 = h1;

    h1 = "hi dad!";

    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;

    return 0;
}
