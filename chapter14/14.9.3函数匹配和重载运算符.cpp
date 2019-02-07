/*

    重载的运算符也是重载的函数（ 一个类可能operator+ 是成员函数也可能是友元函数 这就是重载 ）
    如果你定义了成员函数operator+和友元函数operator+，则调用形式是区分不出来你调用的是成员函数还是非成员函数
    a+b是区分不出是调用成员函数还是友元函数
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
    SmallInt s1,s2;
    SmallInt s3 = s1 + s2;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    //int i = s3 + 0;  //二义性错误
    //  1.我们可以把0转换成SmallInt，然后使用SmallInt的+
    //  2.我们也可以把s3转换成int然后对2个int执行内置的加法运算
    SmallInt s4(3.14);
    cout<<s4<<endl;


    return 0;
}
