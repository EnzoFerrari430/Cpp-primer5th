#include <iostream>
#include "Bulk_quote.h"
#include "Tiny_quote.h"
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
    Bulk_quote oBuo("Windows program",60,100,0.3);
    Tiny_quote oTuo("STL analyse",60,120,0.2);
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

    //practice  15.17
    //Disc_quote oDuo;  cannot declare variable 'oDuo' to be of abstract type 'Disc_quote'  ���ܶԳ�������Disc_quote����������


    //15.6�̳��е���������
    Bulk_quote bulk2;
    Bulk_quote *bulk2P = &bulk2;  //��̬���ͺͶ�̬����һ��
    Quote *itemP2 = &bulk2;  //��̬���ͺͶ�̬���Ͳ�һ��
    bulk2P->discount_policy();  //��ȷ��bulk2P�������� ulk_quote *
    //itemP2->discount_policy();  ����  class Quote has no member named 'discount_policy'
    //��ΪitemP2��������Quote��ָ�룬��ζ��discount_policy����������Quote��ʼ,Ȼ�������Ļ���Ѱ��


    //cout << "Hello world!" << endl;
    return 0;
}
