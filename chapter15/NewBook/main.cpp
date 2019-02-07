#include <iostream>
#include "Bulk_quote.h"
#include "Tiny_quote.h"
using namespace std;

double print_total( ostream &os,const Quote &item,size_t n )
{
    //根据传入item形参的对象类型调用Quote::net_price或者Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}


int main()
{
    //practice 15.6
    Quote oQuo("C++ primer",50);
    Bulk_quote oBuo("Windows program",60,100,0.3);
    Tiny_quote oTuo("STL analyse",60,120,0.2);
    print_total(cout,oQuo,120);
    print_total(cout,oBuo,120);
    print_total(cout,oTuo,120);


    //15.2.3类型转换与继承
    /*
        之所以存在派生类向基类的类型转换是因为每个派生类对象都包含一个基类部分
        而一个基类的对象可能是派生类对象的一部分，也可能不是，所以不存在从基类向派生类的自动类型转换
    */
    //Quote base;
    //Bulk_quote *bulkP = &base;  错误 不能将基类转换成派生类
    //Bulk_quote &bulkRef = base; 错误 不能将基类转换成派生类
    //如果上述是合法的，则我们有可能会使用buikP或bulkRef访问base中本不存在的成员


    //即使一个基类指针或引用绑定在一个派生类的对象上了，我们也不能执行从基类向派生类的转换
    Bulk_quote bulk;
    Quote *itemP = &bulk;  //正确，动态类型是Bulk_quote
    //Bulk_quote *bulkP = itemP;  错误，还是不能将基类转换成派生类
    /*
        因为编译器在编译时无法确定某个特定的转换在运行时是否安全，这是因为编译器只能通过检查指针或引用的静态类型来推断该转换是否合法
        1.如果在基类中含有一个或多个虚函数，我们可以使用dynamic_cast请求一个类型转换，该转换的安全检查将在运行时执行
        2.如果已知基类向派生类的转换是安全的，则我们可以使用static_cast来强制覆盖掉编译器的检查工作
    */


    //practice 15.11
    Quote *pQo = &oQuo;
    pQo->debug();
    pQo = &oBuo;
    pQo->debug();
    pQo = &oTuo;
    pQo->debug();

    //practice  15.17
    //Disc_quote oDuo;  cannot declare variable 'oDuo' to be of abstract type 'Disc_quote'  不能对抽象类型Disc_quote类声明变量


    //15.6继承中的类作用域
    Bulk_quote bulk2;
    Bulk_quote *bulk2P = &bulk2;  //静态类型和动态类型一致
    Quote *itemP2 = &bulk2;  //静态类型和动态类型不一致
    bulk2P->discount_policy();  //正确：bulk2P的类型是 ulk_quote *
    //itemP2->discount_policy();  报错  class Quote has no member named 'discount_policy'
    //因为itemP2的类型是Quote的指针，意味着discount_policy的搜索将从Quote开始,然后往它的基类寻找


    //cout << "Hello world!" << endl;
    return 0;
}
