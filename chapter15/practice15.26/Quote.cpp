#include "Quote.h"

void Quote::debug()const
{
    std::cout<<"Class Quote has menber bookNo and price.Their values are: "<<bookNo<<" "<<price<<std::endl;
}

Quote::Quote(const Quote &item)
{
    bookNo = item.bookNo;
    price = item.price;
    std::cout<<"copy construction in Quote"<<std::endl;


}

Quote& Quote::operator=(const Quote& rhs)
{
    if(this != &rhs)
    {
        bookNo = rhs.bookNo;
        price = rhs.price;
    }
    std::cout<<"copy operation= in Quote"<<std::endl;
    return *this;
}

Quote::Quote(Quote &&item)noexcept
{
    bookNo = std::move(item.bookNo);
    price = std::move(item.price);
    std::cout<<"move construction in Quote"<<std::endl;
}

Quote& Quote::operator=(Quote &&rhs)noexcept
{
    if(this != &rhs)
    {
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
    }
    std::cout<<"move operator= in Quote"<<std::endl;
    return *this;
}
