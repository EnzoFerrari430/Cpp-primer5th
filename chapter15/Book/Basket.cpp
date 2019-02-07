#include "Basket.h"
#include "GlobalFun.h"


//将购物篮的内容逐项打印成清单。然后返回购物篮中所有物品的总价格
double Basket::total_receipt(std::ostream &os)const
{
    double sum = 0.0;  //保存实时计算出的总价格

    //返回一个迭代器，指向第一个关键字大于k的元素
    //count函数返回关键字等于k的数量
    for(auto iter = items.cbegin() ; iter  != items.cend() ; iter = items.upper_bound(*iter))
    {
        //我们知道当前的Basket中至少有一个该关键字的元素
        //打印该书籍对应的项目
        sum += print_total(os,**iter,items.count(*iter));
    }
    os << "Total sale: "<<sum<<std::endl;
    return sum;
}
