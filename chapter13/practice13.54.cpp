#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:
    HasPtr(const string &s = string(),int n = 0 ):ps(new string(s)),i(n){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    //HasPtr& operator=(const HasPtr&);
    //HasPtr& operator=(HasPtr rhs);  交换版本
    HasPtr& operator=(HasPtr &&rhs)noexcept;
    ~HasPtr(){delete ps;}
public:
    string *ps;
    int i;
};

//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//    cout<<"Reference Version"<<endl;
//    auto newp = new string(*rhs.ps);
//    delete ps;  //先释放原先那块内存,切记切记,
//    //★★如果rhs和*this是同一个对象，我们就将从已释放的内存中拷贝数据。所以要先拷贝到临时变量中去
//    ps = newp;  //从右侧运算对象拷贝数据到本对象
//    i = rhs.i;
//    return *this;
//}

//交换版本
//HasPtr& HasPtr::operator=(HasPtr rhs)
//{
//    cout<<"normal Version"<<endl;
//    swap(*this,rhs);  //这个版本不用考虑rhs和this指针指向的是不是同一个对象
//    return *this;
//}

inline void swap(HasPtr& lhs,HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);  //交换指针
    swap(lhs.i,rhs.i);  //交换int成员
}


//移动赋值运算符
HasPtr& HasPtr::operator=(HasPtr &&rhs)noexcept
{
    if( this != &rhs )
    {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    std::cout<<"move assignment"<<std::endl;
    return *this;
}


int main()
{
    HasPtr p1("hello world",1);
    HasPtr p2("www.google.com",2);

//    cout<<p1.ps<<" "<<p2.ps<<endl;
//    cout<<p1.i<<" "<<p2.i<<endl;
//    cout<<*p1.ps<<" "<<*p2.ps<<endl;
//
//    swap(p1,p2);
//
//    cout<<p1.ps<<" "<<p2.ps<<endl;
//    cout<<p1.i<<" "<<p2.i<<endl;
//    cout<<*p1.ps<<" "<<*p2.ps<<endl;

    HasPtr p3;
    p3 = std::move(p1);  //这样会出错  2中赋值运算符都能匹配上，而且优先级相同。所以会出二义性
    cout<<*p2.ps<<endl;
    //cout<<*p1.ps<<endl;

    //p1 = std::move(p1);  //一定要先排除自赋值情况
    //cout<<*p1.ps<<endl;

    return 0;
}
