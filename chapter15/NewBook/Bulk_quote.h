#ifndef BULK_QUOTE_H_INCLUDED
#define BULK_QUOTE_H_INCLUDED

#include "Disc_quote.h"
//����min_qty�����Ż�

//15.4  �޸Ĳ��ԣ������̳���Disc_quote����ֱ�Ӽ̳�Quote
//ͬһ�鼮������������ĳ��ֵʱ�����ۿ�

//�����๹�캯��ֻ��ʼ������ֱ�ӻ���
class Bulk_quote: public Disc_quote
{
public:
    //���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
    virtual double net_price(std::size_t)const override;  //Ҫϰ����ǰ�����virtual  ��Ϊ�е�VS�汾��֧��override C++11������

    //practice 15.11
    //virtual void debug()const override;
    //std::size_t Getmin_qty()const{return min_qty;}
    //double Getdiscount()const{return discount;}



    //practice15.26
    //��Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա���ᱻ�̳�
    Bulk_quote() = default;
    //���������ֱ�ӻ����м̳ж���
    //Bulk_quote(const std::string &,double,std::size_t,double);
    using Disc_quote::Disc_quote;
    //��ʵ���Լ��Ŀ������Ƴ�Ա
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
    //std::size_t min_qty = 0;  //�ʺ��ۿ����ߵ���͹�����  //������Ҫ��Щ��Ա
    //double discount = 0.0;  //��С����ʾ���ۿ���Ϣ
};

#endif // BULK_QUOTE_H_INCLUDED
