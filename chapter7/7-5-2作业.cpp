#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
public:
    Sales_data(){cout<<"Ĭ�Ϲ��캯��"<<endl;}
    Sales_data(string s,unsigned cnt,double pc):bookNo(s),units_sold(cnt),price(pc){cout<<"3�������캯��"<<endl;}

    Sales_data(string s):Sales_data(){cout<<"ί��1���캯��"<<endl;}
    Sales_data(string s,unsigned cnt):Sales_data(s,cnt,33){cout<<"ί��2���캯��"<<endl;}  //�����ظ�����s��cnt

    string bookNo;
    unsigned units_sold = 0;
    double price = 0;

};

int main()
{
    Sales_data C;

    /*
    ��һ�����캯��ί�и���һ�����캯��ʱ����ί�еĹ��캯���ĳ�ʼֵ�б�ͺ����嶼���α�ִ�С���Sales_data���У���ί�еĹ��캯���ĳ�ʼֵ�б�
    �ͺ����屻һ��ִ�С���Sales_data���У���ί�еĹ��캯����ǡ���ǿյġ����纯��������д���Ļ�������ִ����Щ���룬Ȼ�����Ȩ�Żύ����
    ί���ߵĺ�����
    */
    Sales_data book2("C++");
    Sales_data book3("python",5);

    return 0;
}
