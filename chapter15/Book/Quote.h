#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED

#include <string>
#include <iostream>
class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price){}
    std::string isbn()const{return bookNo;}

    //���ظ����������鼮�������ܶ�
    //�����ฺ���д��ʹ�ò�ͬ���ۿ��㷨
    virtual double net_price(std::size_t n)const{return n * price;}  //����Ͱ�ԭ������
    //virtual ~Quote() = default;  //�������������ж�̬��
    virtual ~Quote(){std::cout<<"virtual destruction in Quote"<<std::endl;}

    //practice 15.11
    virtual void debug()const;
    std::string GetbookNo()const{return bookNo;}
    double Getprice()const{return price;}

    //15.7.2�ƶ�������̳�
    Quote(const Quote&) = default;                  //�Գ�Ա���ο���
    Quote(Quote &&)noexcept = default;              //�Գ�Ա�����ƶ�
    Quote& operator=(const Quote&) = default;       //������ֵ
    Quote& operator=(Quote &&)noexcept = default;   //�ƶ���ֵ


    //Basket add_item�����ڷ����ڴ��ʱ�򣬿��ܻ���ִ�����Ϊnewֻ�ܷ���һ��Quote���ͣ�����������Bulk_quote�Ļ����ö������е������Ĳ���
    //Ϊ�����������⣬���Ǹ�Quote�����һ���麯�����ú���������һ�ݵ�ǰ����Ŀ���
    virtual Quote* clone() const &{return new Quote(*this);}  // һ��&  ������ֵ
    virtual Quote* clone() &&{return new Quote(std::move(*this));}  //2��&&  ������ֵ

private:
    std::string bookNo;  //�鼮��ISBN���
protected:
    double price = 0.0;  //������ͨ״̬�²����۵ļ۸�
};

#endif // QUOTE_H_INCLUDED
