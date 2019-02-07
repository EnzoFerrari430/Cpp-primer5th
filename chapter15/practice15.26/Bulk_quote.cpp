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

//要显式的调用该函数
Bulk_quote::Bulk_quote( const Bulk_quote& rhs):Quote(rhs)
{
    min_qty = rhs.min_qty;
    discount = rhs.discount;
    std::cout<<"copy construction in Bulk_quote"<<std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote &&rhs)noexcept:Quote(rhs)
{
    min_qty = std::move(rhs.min_qty);
    discount = std::move(rhs.discount);
    std::cout<<"move construction in Bulk_quote"<<std::endl;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs)
{
    //显式的为基类部分赋值
    Quote::operator=(rhs);
    if(this != &rhs )
    {
        min_qty = rhs.min_qty;
        discount = rhs.discount;
    }
    std::cout<<"copy operator= in Bulk_quote"<<std::endl;
    return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote &&rhs)noexcept
{
    //显式的为基类部分赋值
    Quote::operator=(rhs);
    if(this != &rhs)
    {
        min_qty = rhs.min_qty;
        discount = rhs.discount;
    }
    std::cout<<"move operator= in Bulk_quote"<<std::endl;
    return *this;
}


