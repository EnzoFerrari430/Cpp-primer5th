#ifndef BULK_QUOTE_H_INCLUDED
#define BULK_QUOTE_H_INCLUDED

#include "Quote.h"
//大于min_qty给予优惠

//同一书籍的销售量超过某个值时启动折扣
class Bulk_quote: public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &,double,std::size_t,double);
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    virtual double net_price(std::size_t)const override;  //要习惯在前面加上virtual  因为有的VS版本不支持override C++11新特性

    //practice 15.11
    virtual void debug()const override;
    std::size_t Getmin_qty()const{return min_qty;}
    double Getdiscount()const{return discount;}

    //15.7.1虚析构函数
    virtual ~Bulk_quote(){std::cout<<"virtual destruction in Bulk_quote"<<std::endl;}


    //覆盖Quote类的clone函数
    virtual Bulk_quote* clone() const & override {return new Bulk_quote(*this);}  // 一个&  返回左值
    virtual Bulk_quote* clone() && override{return new Bulk_quote(std::move(*this));}  //2个&&  返回右值

private:
    std::size_t min_qty = 0;  //适合折扣政策的最低购买量
    double discount = 0.0;  //以小数表示的折扣信息
};

#endif // BULK_QUOTE_H_INCLUDED
