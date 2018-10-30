#include <iostream>
#include <string>
using namespace std;
/*
    7.56 该成员直接与类本身有关，而不是与类的各个对象保持关联，可以通过在成员声明之前加上关键字static使得与其类关联在一起
        优点： 每个对象不需要存储一个公共的数据，如果数据改变了，则每个对象都能使用新的值
        与普通成员的区别：1.静态数据成员可以是不完全类型
                          2.静态成员可以作为默认实参
*/

//7.57
class Account
{
public:
    void total(){amount += amount * yearRate;}
    static double rate(){return yearRate;}  //static函数不包含this指针    return的yearRate就是static的
    static void rate(double newRate){yearRate = newRate;}

private:
    string owner;
    double amount;  //本金
    static double yearRate;  //年利率
    static constexpr double nowRate = 4.33;
    static double initRate(){return nowRate;}

};

//定义并初始化一个静态成员
double Account::yearRate = initRate();





int main()
{


    return 0;
}
