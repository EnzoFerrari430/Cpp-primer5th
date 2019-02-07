#include "Tiny_quote.h"
Tiny_quote::Tiny_quote(const std::string &book,double p,std::size_t cnt,double con)
:Disc_quote(book,p,cnt,con)
{

}

double Tiny_quote::net_price(std::size_t sales)const
{
    if(sales <= quantity)
    {
        return price * sales * (1 - discount);
    }
    else
    {
        return price * sales;
    }
}

//void Tiny_quote::debug()const
//{
//    Quote::debug();
//    std::cout<<"Class Tiny_quote has menber max_qty and dic.Their values are: "<<max_qty<<" "<<dic<<std::endl;
//}
