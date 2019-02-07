#include "Bulk_quote.h"

//ÿ����������Լ��ĳ�Ա��ʼ������
//book �� p���ݸ�Quote�Ĺ��캯������Quote�Ĺ��캯������ʼ��Bulk_quote�Ļ��ಿ�֡�
//15.4  ����ĳ���Disc_quote  ���캯��Ҫ���¸�
Bulk_quote::Bulk_quote(const std::string &book,double p,std::size_t qty,double disc)
    :Quote(book,p)
    ,min_qty(qty)
    ,discount(disc)
{

}

//������ʹ�û���
//��������Է��ʻ���Ĺ��г�Ա���ܱ�����Ա
double Bulk_quote::net_price(std::size_t cnt)const
{
    if(cnt >= min_qty)
    {
        return cnt * (price * (1 - discount) );
    }
    else
    {
        return cnt * price;
    }
}

void Bulk_quote::debug()const
{
    Quote::debug();  //���û���debug��������ʾ���������
    std::cout<<"Class Bulk_quote has menber min_qty and disc.Their values are: "<<min_qty<<" "<<discount<<std::endl;
}

//Ҫ��ʽ�ĵ��øú���
Bulk_quote::Bulk_quote( const Bulk_quote& rhs):Quote(rhs)
{
    min_qty = rhs.min_qty;
    discount = rhs.discount;
    std::cout<<"copy construction in Bulk_quote"<<std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote &&rhs)noexcept:Quote(rhs)
{
    min_qty = std::move(rhs.min_qty);
    discount = std::move(rhs.discount);
    std::cout<<"move construction in Bulk_quote"<<std::endl;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs)
{
    //��ʽ��Ϊ���ಿ�ָ�ֵ
    Quote::operator=(rhs);
    if(this != &rhs )
    {
        min_qty = rhs.min_qty;
        discount = rhs.discount;
    }
    std::cout<<"copy operator= in Bulk_quote"<<std::endl;
    return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote &&rhs)noexcept
{
    //��ʽ��Ϊ���ಿ�ָ�ֵ
    Quote::operator=(rhs);
    if(this != &rhs)
    {
        min_qty = rhs.min_qty;
        discount = rhs.discount;
    }
    std::cout<<"move operator= in Bulk_quote"<<std::endl;
    return *this;
}


