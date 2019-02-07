#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


/*
    我们能定义对于类类型的转换，通过定义类型转换运算符可以做到这一点。
    转换构造函数和类型转换运算符共同定义了类类型转换
    这样的转换有时也被称作用户定义的类型转换
*/

/*
    类型转换运算符负责将一个类类型的值转换成其他类型，一般形式如下
    operator type() const;    type可以是任意类型但是不能是void

    只要该类型能作为函数的返回类型。所以我们不允许转换成数组，或者函数类型，但是允许转换成指针或者引用类型
*/

//表示0-255之间的数
class SmallInt
{
public:
    SmallInt(int i = 0):val(i){
        if(i < 0 || i > 255)
        {
            throw std::out_of_range("Bad SmallInt Value");
        }
    }
    //operator int()const{return val;}
    explicit operator int() const{return val;}  //explicit显式的类型转换运算符  这样编译器不会自动执行这一类型转换
private:
    std::size_t val;

};

int main()
{
    SmallInt si = 4;  //先将4隐式转换成SmallInt，然后调用SmallInt::operator=
    //cout<<si + 3<<endl;  //先将si隐式的转换成int，然后执行整数的加法  现在这里要将隐式的类型转换变成显示的类型转换
    cout<<static_cast<int>(si) + 3<<endl;

    SmallInt s2 = 3.14;  //调用SmallInt(int)构造函数
    //cout<<s2 + 3.14<<endl;  //s2先转成int再转成double得到6.14
    cout<<static_cast<int>(s2) + 3.14<<endl;
    SmallInt s3 = 1000;


    //int i = 42;
    //cin<<i;  //如果向bool的类型转换不是显示的，则该代码在编译器看来将是合法的。  编译器会通过编译
    //istream的bool类型转换运算符将cin转换成bool，而这个bool值接着会提升成int  结果就是一个int值（1或0）被左移42位


    return 0;
}
