#include <iostream>
#include <string>

using namespace std;

//13.29因为swap函数里面的swap函数的参数不是HasPtr&,HasPtr&。
//不能使用类自己定义的swap版本。系统会自己将函数匹配成std的swap版本，所以不会发生递归


//类都有他自己的内存空间
class HasPtr
{
    friend void swap(HasPtr& lhs,HasPtr& rhs);
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string);
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

HasPtr& HasPtr::operator=(const string rhs)
{
    auto newp = new string(rhs);
    delete ps;  //先释放原先那块内存,切记切记,
    //★★如果rhs和*this是同一个对象，我们就将从已释放的内存中拷贝数据。所以要先拷贝到临时变量中去
    ps = newp;  //从右侧运算对象拷贝数据到本对象
    return *this;
}

void swap(HasPtr& lhs,HasPtr& rhs)
{
    cout<<"swap now"<<endl;
//    int temp;
//    string s;
//    s = *lhs.ps;
//    *lhs.ps = *rhs.ps;
//    *rhs.ps = s;
//    temp = lhs.i;
//    lhs.i = rhs.i;
//    rhs.i = lhs.i;
    //改变指针指向
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

int main()
{
    HasPtr h1("hi mom!");
    HasPtr h2(h1);
    HasPtr h3 = h1;


    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;
    cout<<"h3: "<<*h3.ps<<endl;
    cout<<"h1: "<<h1.ps<<endl;
    cout<<"h2: "<<h2.ps<<endl;
    cout<<"h3: "<<h3.ps<<endl;

    h2 = "hi dad";
    h3 = "hi son";
    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;
    cout<<"h3: "<<*h3.ps<<endl;
    cout<<"h1: "<<h1.ps<<endl;
    cout<<"h2: "<<h2.ps<<endl;
    cout<<"h3: "<<h3.ps<<endl;

    swap(h2,h3);

    cout<<"h1: "<<*h1.ps<<endl;
    cout<<"h2: "<<*h2.ps<<endl;
    cout<<"h3: "<<*h3.ps<<endl;
    cout<<"h1: "<<h1.ps<<endl;
    cout<<"h2: "<<h2.ps<<endl;
    cout<<"h3: "<<h3.ps<<endl;


    return 0;
}
