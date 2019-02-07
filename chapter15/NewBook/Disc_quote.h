#ifndef DISC_QUOTE_H_INCLUDED
#define DISC_QUOTE_H_INCLUDED

//15.4  抽象基类
#include "Quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book,double price,std::size_t qty,double disc):Quote(book,price),quantity(qty),discount(disc){}
    virtual double net_price(std::size_t)const = 0;  //  =0只能出现在类内部的虚函数声明处
    //我们可以为纯虚函数提供定义，不过函数体必须定义在类的外部


    //15.6继承中的类作用域
    /*
        当存在继承关系时，派生类的作用域嵌套在其基类的作用域之内。
        如果一个名字在派生类的作用域内无法正确解析，则编译器将继续在外层的基类作用域中寻找该名字的定义

        即使静态类型与动态类型不一致
        但是我们能使用哪些成员仍然是由静态类型决定的
    */

    std::pair<size_t,double> discount_policy()const
    {
        return {quantity,discount};
    }



protected:
    std::size_t quantity = 0;  //折扣适用的购买量
    double discount = 0.0;  //表示折扣的小数值
};



#endif // DISC_QUOTE_H_INCLUDED
