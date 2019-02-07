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

    //返回给定数量的书籍的销售总额
    //派生类负责改写并使用不同的折扣算法
    virtual double net_price(std::size_t n)const{return n * price;}  //基类就按原价卖。
    //virtual ~Quote() = default;  //对析构函数进行动态绑定
    virtual ~Quote(){std::cout<<"virtual destruction in Quote"<<std::endl;}

    //practice 15.11
    virtual void debug()const;
    std::string GetbookNo()const{return bookNo;}
    double Getprice()const{return price;}

    //15.7.2移动操作与继承
    Quote(const Quote&);                  //对成员依次拷贝
    Quote(Quote &&)noexcept;              //对成员依次移动
    Quote& operator=(const Quote&);       //拷贝赋值
    Quote& operator=(Quote &&)noexcept;   //移动赋值
private:
    std::string bookNo;  //书籍的ISBN编号
protected:
    double price = 0.0;  //代表普通状态下不打折的价格
};

#endif // QUOTE_H_INCLUDED
