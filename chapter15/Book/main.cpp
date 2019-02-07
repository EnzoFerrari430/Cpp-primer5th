#include <iostream>
#include <vector>
#include <memory>
#include "Bulk_quote.h"
#include "Tiny_quote.h"
#include "Basket.h"
#include "GlobalFun.h"
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
    Bulk_quote oBuo("Windows program",60,100,0.3);  //这个构造函数先构造了Quote，然后在构造自己
    Tiny_quote oTuo("STL analyse",60,120,0.2);  //这个构造函数先构造了Quote，然后在构造自己
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



    cout<<"15.7.1虚析构的功能演示"<<endl;
    Quote *itemp = new Quote;
    delete itemp;
    itemp = new Bulk_quote;  //Bulk_quote有Quote的成员，会先构造Quote再构造自己,该itemP指针还是指向Bulk_quote类中自己的部分
    delete itemp;
    cout<<"演示完毕"<<endl;


    //15.8在容器中要放入继承体系中的基类指针，因为这个指针所指对象的动态类型可能是基类也可以是派生类
    //vector<Quote*> pQuos;

    //practice 15.28
    vector<Quote> v;
    for(int i = 0 ; i < 5; ++i )
    {
        v.push_back(Bulk_quote("sss",i*11,10,0.3));
    }
    double total1 = 0.0;
    for( const auto& b : v)
    {
        total1 += b.net_price(20);
    }
    cout<<total1<<endl;
    cout<<"====================="<<endl;

    //practice 15.29
    vector<shared_ptr<Quote>> pQuos;
    for(int i = 0 ; i < 5 ; ++i )
    {
        pQuos.push_back(make_shared<Bulk_quote>(Bulk_quote("sss",i*11,10,0.3)));
    }
    double total2 = 0.0;
    for( const auto& b : pQuos)
    {
        total2 += b->net_price(20);
    }
    cout<<total2<<endl;
    cout<<"====================="<<endl;

    //practice 15.30
    Basket bsk;
    string Book_names[5] = {"aaa","bbb","ccc","ddd","eee"};
    for(int i = 0 ; i < 5 ; ++i)
    {
        //这个函数写的不是很好，应该再加一个表示数量的参数
        bsk.add_item(Bulk_quote(Book_names[i],(i+1)*11,10,0.3));
    }


    int n = bsk.total_receipt(cout);
    //cout << "Hello world!" << endl;
    return 0;
}
