#include <iostream>
#include <ostream>
#include <istream>
using namespace std;
/*
    oop(面向对象程序设计)的核心思想是：数据抽象，继承和动态绑定
*/
//继承：基类负责定义在层次关系中所有类共同拥有的成员，而每个派生类定义各自特有的成员

//定义一个Quote类，将它作为层次关系中的基类，Quote的对象表示按原价销售的书籍
//Quote派生出的另一个名为Bulk_quote类，表示可以打折出售的书籍
/*
    这些类包含下面两个成员函数
    isbn(),返回书籍的ibsn编号。该操作不涉及派生类的特殊性，因此只定义在Quote类中。
    net_price(size_t)，返回书籍的实际销售价格，前提是用户购买该书的数量达到一定标准。这个操作显然是与类型有关的，Quote和Bulk_quote都应该包含该函数
*/
class Quote
{
public:
    std::string isbn()const;
    virtual double net_price(std::size_t n)const;
};

//派生类必须通过使用派生类列表明确指出它自己是从哪个（哪些）基类继承而来。派生类列表形式：  首先是一个冒号，后面紧跟以逗号分隔的基类列表，每个基类前面可有访问说明符
class Bulk_quote : public Quote
{
public:
    virtual double net_price(std::size_t n)const override;  //virtual可加可不加，override是C++11新特性带进来注明该成员函数改写了基类的虚函数
};

//动态绑定，可以用同一段代码分别处理Quote和Bulk_quote的对象
//计算并打印销售给定数量的某种书籍所得的费用
double print_total( ostream &os,const Quote &item,size_t n )
{
    //根据传入item形参的对象类型调用Quote::net_price或者Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}
//上述函数的运行版本由实参决定，即在运行时选择函数的版本，所以动态绑定有时又被称为运行时绑定。

//  ！！当我们使用基类的引用或指针调用一个虚函数时将发生动态绑定。


int main()
{


    return 0;
}
