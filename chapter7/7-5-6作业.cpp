#include <iostream>
using namespace std;

class Debug
{
public:
    constexpr Debug(bool b = true):hw(b),io(b),other(b){}  //constexpr声明的函数体 只能拥有一条return语句,与构造函数的不能有return结合，所以
    constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}  //函数体只能为空

    constexpr bool any(){return hw || io || other;}

    void set_io(bool b){io = b;}
    void set_hw(bool b){hw = b;}
    void set_other(bool b){hw = b;}
private:
    bool hw;  //硬件错误
    bool io;  //IO错误
    bool other;  //其他错误
};


//7.54 不可以，constexpr函数体只能是return语句

int main()
{


    return 0;
}
