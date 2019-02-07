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


struct LongDouble
{
    //通常情况下 + 是个非成员
    LongDouble operator+(const SmallInt &);
    LongDouble(double = 0.0);
    operator double();
    operator float();

};
LongDouble operator+(LongDouble &,double);
int main()
{
    SmallInt si;
    LongDouble ld;
    ld = si + ld;
    /*
        候选函数：
        1.friend SmallInt operator+(const SmallInt &,const SmallInt &);  ld没有转int的类型转换，这个operator+不行
        2.内置类型  operator+(int + float) operator+(int + double) si可以转换成int ld可以转换成float或者double会产生二义性
        3.
    */

    ld = ld + si;
    /*
        候选函数：
        1.LongDouble operator+(const SmallInt &);
        2.LongDouble operator+(LongDouble &,double);  si转换成int再转换成double
        这2种方式都能实现，但是第一种是精确匹配，优先级高
    */


    return 0;
}
