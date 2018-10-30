#include <iostream>
#include <string>
using namespace std;
/*
    可以通过将构造函数声明为explicit阻止隐式转换

    关键字explicit只对一个实参的构造函数有效，需要多个实参的构造函数不能用于执行隐式转换

    只能在类内声明构造函数时使用explicit关键字，在外部定义时不应重复
*/
class Sales_data
{
public:
    Sales_data() = default;
    Sales_data(const string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
    explicit Sales_data(const string &s):bookNo(s){}
    explicit Sales_data(istream&);
    bool isSame(const Sales_data &r)
    {
        return bookNo == r.bookNo;
    }
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

int main()
{
    Sales_data itema("aaa");
    //itema.isSame(string("bbb"));  加了explicit，阻止了string转成Sales_data型
    itema.isSame(Sales_data("ccc"));  //但是可以显式的构造一个Sales_data对象

    return 0;
}
