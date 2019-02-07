#ifndef DISC_QUOTE_H_INCLUDED
#define DISC_QUOTE_H_INCLUDED

//15.4  �������
#include "Quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book,double price,std::size_t qty,double disc):Quote(book,price),quantity(qty),discount(disc){}
    virtual double net_price(std::size_t)const = 0;  //  =0ֻ�ܳ��������ڲ����麯��������
    //���ǿ���Ϊ���麯���ṩ���壬������������붨��������ⲿ
protected:
    std::size_t quantity = 0;  //�ۿ����õĹ�����
    double discount = 0.0;  //��ʾ�ۿ۵�С��ֵ
};



#endif // DISC_QUOTE_H_INCLUDED
