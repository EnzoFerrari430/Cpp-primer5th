#include "Tiny_quote.h"
Tiny_quote::Tiny_quote(const std::string &book,double p,std::size_t cnt,double con)
:Quote(book,p)
,max_qty(cnt)
,dic(con)
{

}

double Tiny_quote::net_price(std::size_t sales)const
{
    if(sales <= max_qty)
    {
        return price * sales * (1 - dic);
    }
    else
    {
        return price * sales;
    }
}

void Tiny_quote::debug()const
{
    Quote::debug();
    std::cout<<"Class Tiny_quote has menber max_qty and dic.Their values are: "<<max_qty<<" "<<dic<<std::endl;
}
