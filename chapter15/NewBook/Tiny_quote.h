#ifndef TINY_QUOTE_H_INCLUDED
#define TINY_QUOTE_H_INCLUDED

//#include "Quote.h"
//practice15.16  重构，使其继承自Disc_quote
#include "Disc_quote.h"


//小于max_qty给予优惠
class Tiny_quote : public Disc_quote
{
public:
    Tiny_quote() = default;
    Tiny_quote(const std::string&,double,std::size_t max_qty,double );
    virtual double net_price(std::size_t)const override;

    //practice 15.11
    //virtual void debug()const override;
    //double Getdic()const{return dic;}
    //std::size_t Getmax_qty()const {return max_qty;}
private:
    //double dic;
    //std::size_t max_qty;
};


#endif // TINY_QUOTE_H_INCLUDED
