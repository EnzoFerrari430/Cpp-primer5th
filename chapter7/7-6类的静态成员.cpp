#include <iostream>
#include <string>
using namespace std;

//我们通过在成员的声明之前加上关键字static使得其与类关联在一起。和其他成员一样，静态成员可以是public或者private
//静态数据成员可以是常量，引用，指针，类类型等

class Account
{
public:
    void calculate(){amount +=amount * interestRate;}  //成员函数不用通过作用域运算符就能是直接使用静态成员
    static double rate(){return interestRate;}
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();

    //通常类的静态成员不应该在类的内部初始化。但我们可以为静态成员提供const整数类型的类内初始值
    //不过要求静态成员必须是字面值常量类型constexpr，初始值必须是常量表达式，这些成员能用在所有适用于常量表达式的地方。
    static constexpr int period = 30;
    double daily_tbl[period];
    //如果该成员仅在编译器可以替代它的值的情况下，则初始化一个const或者constexpr static不需要单独定义
    //意思就是如果period就是在内部使用，那么定义就不用分离，类内初始化就足够了，但如果在类外使用，就会出现编译错误
    //相反的，则该成员必须有一条定义语句
};

//★类的静态成员存在于任何对象之外，对象中不包含任何与静态数据成员有关的数据。
//所以每个Account对象将包含两个数据成员：owner和amount。只存在一个interestRate对象而且被所有Account对象共享

//类似的，静态成员函数也不与任何对象绑定在一起，它们不包含this指针。作为结果，静态成员函数不能声明成const
//不能在static函数体内使用this指针。


//★静态成员函数可以定义在类的内部也可以定义在类的外部，当在类的外部时，不能重复static关键字，该关键字只出现在类内部的声明语句
void Account::rate(double newRate)
{
    interestRate = newRate;
}

//定义并初始化一个静态成员
//类型名 类名 作用域运算符 成员自己的名字
double Account::interestRate = initRate();  //静态成员变量的定义也可以访问类的私有成员

//静态成员函数的地址可以存储在一个常规的函数指针中，而不是指向成员函数的指针中

int main()
{
    //作用域运算符直接访问静态成员
    double r;
    r = Account::rate();

    //虽然静态成员不属于类的某个对象，但是我们仍然可以使用类的对象、引用或者指针来访问静态成员

    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();

    return 0;
}
