#include <iostream>
#include <string>

/*
    C++11�±�׼��չ�˹��캯����ʼֵ�Ĺ��ܣ�ί�й��캯��
    һ��ί�й��캯��ʹ������������������캯��ִ�����Լ��ĳ�ʼ������

    һ��ί�й��캯��Ҳ��һ����Ա��ʼֵ�б��һ��������
*/


using namespace std;

class Sales_data
{
public:
    //��ί�й��캯��
    Sales_data(string s,unsigned cnt,double price):bookNo(s),units_sold(cnt),revenue(cnt*price){}
    //����Ĺ��캯��ȫ��ί�и���һ�����캯��
    Sales_data():Sales_data("",0,0){}

    Sales_data(string s):Sales_data(s,0,0){}

    Sales_data(istream &is):Sales_data(){read(is,*this);}
};

int main()
{


    return 0;
}
