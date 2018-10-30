#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    //浅拷贝
    HasPtr(const std::string &s = std::string() ):ps(new std::string(s)),i(0){}

    HasPtr& operator=(const std::string &s);

    ~HasPtr(){ delete ps; }

public:
    std::string *ps;
    int i;
};

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
