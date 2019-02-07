#ifndef BULK_QUOTE_H_INCLUDED
#define BULK_QUOTE_H_INCLUDED

#include "Quote.h"
//����min_qty�����Ż�

//ͬһ�鼮������������ĳ��ֵʱ�����ۿ�
class Bulk_quote: public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &,double,std::size_t,double);
    //���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
    virtual double net_price(std::size_t)const override;  //Ҫϰ����ǰ�����virtual  ��Ϊ�е�VS�汾��֧��override C++11������

    //practice 15.11
    virtual void debug()const override;
    std::size_t Getmin_qty()const{return min_qty;}
    double Getdiscount()const{return discount;}

    //15.7.1����������
    virtual ~Bulk_quote(){std::cout<<"virtual destruction in Bulk_quote"<<std::endl;}


    //����Quote���clone����
    virtual Bulk_quote* clone() const & override {return new Bulk_quote(*this);}  // һ��&  ������ֵ
    virtual Bulk_quote* clone() && override{return new Bulk_quote(std::move(*this));}  //2��&&  ������ֵ

private:
    std::size_t min_qty = 0;  //�ʺ��ۿ����ߵ���͹�����
    double discount = 0.0;  //��С����ʾ���ۿ���Ϣ
};

#endif // BULK_QUOTE_H_INCLUDED
