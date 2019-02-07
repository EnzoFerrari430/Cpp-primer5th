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


    //15.6�̳��е���������
    /*
        �����ڼ̳й�ϵʱ���������������Ƕ����������������֮�ڡ�
        ���һ������������������������޷���ȷ������������������������Ļ�����������Ѱ�Ҹ����ֵĶ���

        ��ʹ��̬�����붯̬���Ͳ�һ��
        ����������ʹ����Щ��Ա��Ȼ���ɾ�̬���;�����
    */

    std::pair<size_t,double> discount_policy()const
    {
        return {quantity,discount};
    }



protected:
    std::size_t quantity = 0;  //�ۿ����õĹ�����
    double discount = 0.0;  //��ʾ�ۿ۵�С��ֵ
};



#endif // DISC_QUOTE_H_INCLUDED
