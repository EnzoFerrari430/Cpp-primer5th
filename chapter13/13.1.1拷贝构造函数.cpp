#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数
    拷贝构造函数的第一个参数必须是引用类型

    如果我们没有为一个类定义拷贝构造函数，编译器会为我们定义一个。即使我们定义了其他构造函数，
    编译器也会为我们合成一个拷贝构造函数

    一般情况下合成的拷贝构造函数会将其参数的成员逐个拷贝到正在创建的对象中。编译器从给定对象中一次将每个非static成员拷贝到正在创建的对象中

    每个成员的类型决定了它如何拷贝，对类类型的成员，会使用其拷贝构造函数来拷贝，
    内置类型的成员则直接拷贝。对于数组，合成拷贝构造函数会逐元素拷贝一个数组类型的成员。

    ★★拷贝构造函数被用来初始化非引用类类型的参数，这一特性解释了为什么拷贝构造函数自己的参数必须是引用类型
    如果不是引用类型，则调用永远也不会成功————为了调用拷贝构造函数，我们必须拷贝它的实参，但为了拷贝实参，我们又需要调用拷贝构造函数
    如此无限循环
*/
class Foo
{
public:
    Foo();      //默认构造函数
    Foo(const Foo&);  //拷贝构造函数
};

class Sales_data
{
public:
    //其他成员和构造函数的定义，如前
    //与合成的拷贝构造函数等价的拷贝构造函数声明
    Sales_data(const Sales_data&);
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};
// 与Sales_data的合成拷贝构造函数等价
Sales_data::Sales_data(const Sales_data &orig)
:bookNo(orig.bookNo)
,units_sold(orig.units_sold)
,revenue(orig.revenue)
{

}

/*
拷贝初始化的限制：
    如果我们使用的初始化值要求通过一个explicit的构造函数来进行类型转换，那么使用拷贝初始化还是直接初始化就不是无关紧要的了
*/
vector<int> v1(10);  //正确：直接初始化  10个0
//vector<int> v2 = 10; //错误：接受大小参数的构造函数是explicit的

/*
    ★★拷贝构造函数被用来初始化非引用类类型的参数，这一特性解释了为什么拷贝构造函数自己的参数必须是引用类型
    如果不是引用类型，则调用永远也不会成功————为了调用拷贝构造函数，我们必须拷贝它的实参，但为了拷贝实参，我们又需要调用拷贝构造函数
    如此无限循环
*/
void f(vector<int>);  //f的参数进行拷贝初始化
//f(10);
//f(vector<int>(10));  正确：从一个int直接构造一个临时vector


int main()
{
    for(auto it = v1.begin();it != v1.end();++it)
    {
        cout<<*it<<' ';
    }
    return 0;
}
