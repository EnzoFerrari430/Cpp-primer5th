#ifndef BULK_QUOTE_H_INCLUDED
#define BULK_QUOTE_H_INCLUDED

#include "Disc_quote.h"
//大于min_qty给予优惠

//15.4  修改策略，让它继承自Disc_quote而非直接继承Quote
//同一书籍的销售量超过某个值时启动折扣

//派生类构造函数只初始化它的直接基类
class Bulk_quote: public Disc_quote
{
public:
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    virtual double net_price(std::size_t)const override;  //要习惯在前面加上virtual  因为有的VS版本不支持override C++11新特性

    //practice 15.11
    //virtual void debug()const override;
    //std::size_t Getmin_qty()const{return min_qty;}
    //double Getdiscount()const{return discount;}



    //practice15.26
    //这默认构造函数和拷贝控制成员不会被继承
    Bulk_quote() = default;
    //这个函数从直接基类中继承而来
    //Bulk_quote(const std::string &,double,std::size_t,double);
    using Disc_quote::Disc_quote;
    //再实现自己的拷贝控制成员
    // copy constructor
    Bulk_quote(const Bulk_quote& item) : Disc_quote(item)
    {
        std::cout << "copy construction in Bulk_quote"<<std::endl;
    }

    // move constructor
    Bulk_quote(Bulk_quote&& item)noexcept : Disc_quote(std::move(item))
    {
        std::cout <<"move construction in Bulk_quote"<<std::endl;
    }

    // copy =()
    Bulk_quote& operator =(const Bulk_quote& rhs)
    {
        Disc_quote::operator =(rhs);
        std::cout << "copy operator= in Bulk_quote"<<std::endl;

        return *this;
    }


    // move =()
    Bulk_quote& operator =(Bulk_quote&& rhs)noexcept
    {
        Disc_quote::operator =(std::move(rhs));
        std::cout << "move operator= in bulk_quote"<<std::endl;;

        return *this;
    }

    virtual ~Bulk_quote() override
    {
        std::cout <<"virtual destruction in Bulk_quote"<<std::endl;
    }

private:
    //std::size_t min_qty = 0;  //适合折扣政策的最低购买量  //不再需要这些成员
    //double discount = 0.0;  //以小数表示的折扣信息
};

#endif // BULK_QUOTE_H_INCLUDED
