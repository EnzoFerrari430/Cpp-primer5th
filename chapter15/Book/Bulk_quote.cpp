#include "Bulk_quote.h"

//每个类控制它自己的成员初始化过程
//book 和 p传递给Quote的构造函数，由Quote的构造函数来初始化Bulk_quote的基类部分。
//15.4  基类改成了Disc_quote  构造函数要重新改
Bulk_quote::Bulk_quote(const std::string &book,double p,std::size_t qty,double disc)
    :Quote(book,p)
    ,min_qty(qty)
    ,discount(disc)
{

}

//派生类使用基类
//派生类可以访问基类的公有成员和受保护成员
double Bulk_quote::net_price(std::size_t cnt)const
{
    if(cnt >= min_qty)
    {
        return cnt * (price * (1 - discount) );
    }
    else
    {
        return cnt * price;
    }
}

void Bulk_quote::debug()const
{
    Quote::debug();  //调用基类debug函数，显示基类的数据
    std::cout<<"Class Bulk_quote has menber min_qty and disc.Their values are: "<<min_qty<<" "<<discount<<std::endl;
}
