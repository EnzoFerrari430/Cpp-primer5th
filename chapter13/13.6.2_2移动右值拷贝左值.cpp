#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
using namespace std;

class StrVec
{

public:
    StrVec();
    StrVec(const StrVec &);
    StrVec& operator=(const StrVec &);

    StrVec(StrVec &&) noexcept;
    StrVec& operator=(StrVec &&) noexcept;
    StrVec getVec(istream &);  //getVec返回的是一个右值

private:
    int i;
    char *p;
};

int main()
{
    StrVec v1,v2;
    //这里v2是非常量的，所以v2要先匹配非常量版本的赋值运算符，也就是移动赋值运算符。但是v2是一个左值，所以v2不匹配，然后再去匹配常量版本的拷贝赋值运算符
    v1 = v2;  //v2是左值，使用的是拷贝赋值

    //这里v2是非常量，所以要先匹配非常量版本的赋值运算符，而且getVec返回的是一个右值，正好符合移动赋值运算符的条件。所以这里使用的是移动赋值运算符
    v2 = getVec(cin);  //getVec(cin)是一个右值，使用移动赋值





    return 0;
}
