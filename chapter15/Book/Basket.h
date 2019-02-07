#ifndef BASKET_H_INCLUDED
#define BASKET_H_INCLUDED

#include <memory>
#include <set>
#include <ostream>
#include "Quote.h"

class Basket
{
public:
    //ʹ�úϳɵĹ��캯����Ĭ�ϵĿ������Ƴ�Ա
    //void add_item(const std::shared_ptr<Quote> &sale){items.insert(sale);}  ���¶���ú�����ʹ��������һ��Quote
    void add_item(const Quote& sale){items.insert(std::shared_ptr<Quote>(sale.clone()));}  //���������Ķ���
    void add_item(Quote &&sale){items.insert(std::shared_ptr<Quote>(std::move(sale.clone())));}  //�ƶ������Ķ���


    //��ӡÿ������ܼۺ͹�������������ܼ�
    double total_receipt(std::ostream&)const;
private:
    //�ú������ڱȽ�shared_ptr��multiset��Ա���õ���
    static bool compare(const std::shared_ptr<Quote> &lhs,const std::shared_ptr<Quote> &rhs){return lhs->isbn() < rhs->isbn();}

    //�鱾7.2.2�ڣ�378ҳ    ���ǿ����ṩ�Լ�����Ĳ���������ؼ����ϵ�<�����������ṩ�Ĳ��������ڹؼ��������϶���һ���ϸ�����
    //����multisetʱ���Ǳ����ṩ2�����ͣ��ؼ������ͺͱȽϲ�������(����ָ������)
    //multiset���������ۣ�����compare��Ա����
    std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items{compare};
};
#endif // BASKET_H_INCLUDED
