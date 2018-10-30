#include <iostream>
#include <string>

using namespace std;
//类都有他自己的内存空间
class HasPtr
{
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    HasPtr& operator=(const HasPtr&);
    ~HasPtr(){delete ps;}
private:
    string *ps;
    int i;
};

HasPtr& operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;  //先释放原先那块内存,切记切记,
    //★★如果rhs和*this是同一个对象，我们就将从已释放的内存中拷贝数据。所以要先拷贝到临时变量中去
    ps = newp;  //从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;
}

int main()
{



    return 0;
}
