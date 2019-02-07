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
    //���ݴ���item�βεĶ������͵���Quote::net_price����Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}


int main()
{
    //practice 15.6
    Quote oQuo("C++ primer",50);
    Bulk_quote oBuo("Windows program",60,100,0.3);  //������캯���ȹ�����Quote��Ȼ���ڹ����Լ�
    Tiny_quote oTuo("STL analyse",60,120,0.2);  //������캯���ȹ�����Quote��Ȼ���ڹ����Լ�
    print_total(cout,oQuo,120);
    print_total(cout,oBuo,120);
    print_total(cout,oTuo,120);


    //15.2.3����ת����̳�
    /*
        ֮���Դ�������������������ת������Ϊÿ����������󶼰���һ�����ಿ��
        ��һ������Ķ������������������һ���֣�Ҳ���ܲ��ǣ����Բ����ڴӻ�������������Զ�����ת��
    */
    //Quote base;
    //Bulk_quote *bulkP = &base;  ���� ���ܽ�����ת����������
    //Bulk_quote &bulkRef = base; ���� ���ܽ�����ת����������
    //��������ǺϷ��ģ��������п��ܻ�ʹ��buikP��bulkRef����base�б������ڵĳ�Ա


    //��ʹһ������ָ������ð���һ��������Ķ������ˣ�����Ҳ����ִ�дӻ������������ת��
    Bulk_quote bulk;
    Quote *itemP = &bulk;  //��ȷ����̬������Bulk_quote
    //Bulk_quote *bulkP = itemP;  ���󣬻��ǲ��ܽ�����ת����������
    /*
        ��Ϊ�������ڱ���ʱ�޷�ȷ��ĳ���ض���ת��������ʱ�Ƿ�ȫ��������Ϊ������ֻ��ͨ�����ָ������õľ�̬�������ƶϸ�ת���Ƿ�Ϸ�
        1.����ڻ����к���һ�������麯�������ǿ���ʹ��dynamic_cast����һ������ת������ת���İ�ȫ��齫������ʱִ��
        2.�����֪�������������ת���ǰ�ȫ�ģ������ǿ���ʹ��static_cast��ǿ�Ƹ��ǵ��������ļ�鹤��
    */


    //practice 15.11
    Quote *pQo = &oQuo;
    pQo->debug();
    pQo = &oBuo;
    pQo->debug();
    pQo = &oTuo;
    pQo->debug();



    cout<<"15.7.1�������Ĺ�����ʾ"<<endl;
    Quote *itemp = new Quote;
    delete itemp;
    itemp = new Bulk_quote;  //Bulk_quote��Quote�ĳ�Ա�����ȹ���Quote�ٹ����Լ�,��itemPָ�뻹��ָ��Bulk_quote�����Լ��Ĳ���
    delete itemp;
    cout<<"��ʾ���"<<endl;


    //15.8��������Ҫ����̳���ϵ�еĻ���ָ�룬��Ϊ���ָ����ָ����Ķ�̬���Ϳ����ǻ���Ҳ������������
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
        //�������д�Ĳ��Ǻܺã�Ӧ���ټ�һ����ʾ�����Ĳ���
        bsk.add_item(Bulk_quote(Book_names[i],(i+1)*11,10,0.3));
    }


    int n = bsk.total_receipt(cout);
    //cout << "Hello world!" << endl;
    return 0;
}
