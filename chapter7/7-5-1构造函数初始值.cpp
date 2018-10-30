#include <iostream>
using namespace std;

/*
    有时我们可以忽略成员初始化和赋值的差异，但是如果成员是const或者是引用的话，就必须将其初始化
*/

class ConstRef
{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};

/*
ConstRef::ConstRef(int ii)
{
    //赋值
    i = ii;  //正确
    ci = ii;  //错误   不能给const赋值
    ri = i;   //错误    ri没有初始化
}
*/

//构造函数初始值列表只说明初始化成员的值，而不限定初始化的具体执行顺序
//成员初始化顺序与它们在类定义中的出现顺序一致
//但是如果一个成员是用另一个成员来初始化的，那么这2个成员的初始化顺序就很关键了
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(i){}


int main()
{


    return 0;
}
