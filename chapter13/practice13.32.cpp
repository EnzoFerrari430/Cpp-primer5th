#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr& lhs,HasPtr& rhs);
public:
    //构造函数初始化引用为1  //s默认为空
    HasPtr(const string& s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    //拷贝构造函数
    HasPtr(const HasPtr &rhs);
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr &rhs);
    HasPtr& operator=(const string &rhs);
    ~HasPtr();
public:
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

//13.32  加不加这个和使用默认版本的swap都是交换指针的地址，和i的内容
void swap(HasPtr& lhs,HasPtr& rhs)
{
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
    swap(lhs.use,rhs.use);
}

int main()
{
    HasPtr h1("hi mom!");
    HasPtr h2 = h1;

    h1 = "hi dad!";

    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;

    HasPtr h3("hi h3");
    HasPtr h4("hi h4");
    cout<<"ps address: "<<h3.ps<<" "<<h4.ps<<endl;
    cout<<"ps content: "<<*h3.ps<<" "<<*h4.ps<<endl;
    cout<<"i content: "<<h3.i<<" "<<h4.i<<endl;
    cout<<"use address: "<<h3.use<<" "<<h4.use<<endl;
    cout<<"use content: "<<*h3.use<<" "<<*h4.use<<endl;
    swap(h3,h4);
    cout<<"ps address: "<<h3.ps<<" "<<h4.ps<<endl;
    cout<<"ps content: "<<*h3.ps<<" "<<*h4.ps<<endl;
    cout<<"i content: "<<h3.i<<" "<<h4.i<<endl;
    cout<<"use address: "<<h3.use<<" "<<h4.use<<endl;
    cout<<"use content: "<<*h3.use<<" "<<*h4.use<<endl;

    return 0;
}
