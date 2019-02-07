#include <iostream>
#include <string>

using namespace std;
//类都有他自己的内存空间
class HasPtr
{

    friend void swap(HasPtr&,HasPtr&);
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p);

    //添加移动构造函数
    HasPtr(HasPtr &&p) noexcept:ps(p.ps),i(p.i){p.ps = 0;cout<<"move construct"<<endl;}  //将给定你的HasPtr的指针置为0，从而确保销毁移后源对象是安全的。所以该函数不会抛出异常，标记为noexpect
    //赋值运算符即是移动赋值运算符，也是拷贝赋值运算符，看传的实参的类型区分
    /*
        该运算符有一个非引用参数，这意味着此参数要进行拷贝初始化，！！！这个初始化要依赖实参类型。
        拷贝初始化要么使用拷贝构造函数，要么使用移动构造函数--左值被拷贝，右值被移动。
        因此单一的的运算符就实现了拷贝赋值运算符和移动赋值运算符2种功能
    */
    HasPtr & operator=(HasPtr &&rhs)noexcept;

    //这个拷贝赋值运算符就不需要了
    HasPtr& operator=(const HasPtr&);
    ~HasPtr(){delete ps;}
private:
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
    cout<<"copy assignment"<<endl;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs)noexcept
{
    delete ps;
    ps = rhs.ps;
    i = rhs.i;
    rhs.ps = nullptr;
    cout<<"move assignment"<<endl;
    return *this;
}
inline void swap(HasPtr &lhs,HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

int main()
{
    HasPtr hp,hp2;
    hp = hp2;  //hp2是一个左值，hp2通过拷贝构造函数来拷贝
    //拷贝构造函数分配一个新的string，并拷贝hp2指向的string


    hp = std::move(hp2);  //移动构造函数移动hp2
    //std::move将一个右值绑定到hp2上。此情况下拷贝构造函数和移动构造函数都是可行的。但是实参是一个右值引用，移动构造函数是精确匹配。
    //移动构造函数从hp2拷贝指针，而不会分配内存。





    return 0;
}
