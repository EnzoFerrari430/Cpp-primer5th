#include <iostream>
#include <string>
using namespace std;
/*
    ���캯�����ܱ�������const

    ��ͨ��һ������Ĺ��캯��������Ĭ�ϳ�ʼ������,�����������Ĭ�Ϲ��캯��

    �������û����ʽ�Ķ��幹�캯������ô�������ͻ�Ϊ������ʽ�Ķ���һ��Ĭ�Ϲ��캯��
    �����������Ĺ��캯���ֳ�Ϊ�ϳɵ�Ĭ�Ϲ��캯���������¹���
        1.����������ڵĳ�ʼֵ����������ʼ����Ա
        2.����Ĭ�ϳ�ʼ���ó�Ա
*/

struct Sales_data
{
    //�����Ĺ��캯��
    Sales_data() = default;  //C++11�±�׼ �������ϣ��Ĭ�Ϲ��캯����������ȫ��ͬ�ںϳɵ�Ĭ�Ϲ��캯���������ڲ����б����д�� = default
    Sales_data(const string &s): bookNo(s){}
    //ð���Լ�ð�źͻ�����֮��Ĳ��ֳ�Ϊ���캯����ʼֵ�б�,����Ϊ�´����Ķ����һ���������ݳ�Ա����ֵ
    Sales_data(const string &s,unsigned n,double p): bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(istream &);

    //�������еĳ�Ա
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &);
    double avg_price() const ;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{


    return 0;
}
