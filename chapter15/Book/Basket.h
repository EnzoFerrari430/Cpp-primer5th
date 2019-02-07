#ifndef BASKET_H_INCLUDED
#define BASKET_H_INCLUDED

#include <memory>
#include <set>
#include <ostream>
#include "Quote.h"

class Basket
{
public:
    //使用合成的构造函数和默认的拷贝控制成员
    //void add_item(const std::shared_ptr<Quote> &sale){items.insert(sale);}  重新定义该函数，使得它接受一个Quote
    void add_item(const Quote& sale){items.insert(std::shared_ptr<Quote>(sale.clone()));}  //拷贝给定的对象
    void add_item(Quote &&sale){items.insert(std::shared_ptr<Quote>(std::move(sale.clone())));}  //移动给定的对象


    //打印每本书的总价和购物篮所有书的总价
    double total_receipt(std::ostream&)const;
private:
    //该函数用于比较shared_ptr，multiset成员会用到它
    static bool compare(const std::shared_ptr<Quote> &lhs,const std::shared_ptr<Quote> &rhs){return lhs->isbn() < rhs->isbn();}

    //书本7.2.2节，378页    我们可以提供自己定义的操作来代替关键字上的<操作符。所提供的操作必须在关键字类型上定义一个严格弱序
    //定义multiset时我们必须提供2个类型，关键字类型和比较操作类型(函数指针类型)
    //multiset保存多个报价，按照compare成员排序
    std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items{compare};
};
#endif // BASKET_H_INCLUDED
