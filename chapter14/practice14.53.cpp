/*
    不合法,有2种候选方式
    1.operator+(int , double)
        把si转换成int
    2.friend SmallInt operator+(const SmallInt &,const SmallInt &);
        把3.14转换成int，然后构造一个临时对象

*/

#include <iostream>
using namespace std;
class SmallInt
{
    friend SmallInt operator+(const SmallInt &,const SmallInt &);
public:
    SmallInt(int = 0);  //转换源为int的类型转换
    operator int()const {return val;}  //转换目标为int的类型转换
private:
    std::size_t val;
};

SmallInt::SmallInt(int a)
{
    val = a;
}

SmallInt operator+(const SmallInt &lhs,const SmallInt &rhs)
{

    return lhs.val + rhs.val;
}
int main()
{
    SmallInt s1;
    //double d = s1 + 3.14;
    double d = s1 + SmallInt(3.14);
    cout<<d<<endl;

    return 0;
}
