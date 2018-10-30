#include <iostream>
#include <string>
using namespace std;
/*
    ������߳�����Ҫ����һ����������������add��read  print�ȡ�������Щ��������Ĳ����Ӹ�������˵������Ľӿڵ���ɲ��֣����ǲ������౾��

    ����ǳ�Ա�����ķ�ʽ�붨����������һ����ͨ���Ѻ����������Ͷ�����뿪������������ڸ����������൫�ǲ����������У�
    ����һ������������ͬһ��ͷ�ļ���,�������û�ʹ�ýӿڵ��κβ��ֶ�ֻ��Ҫ����һ���ļ�
*/
struct Sales_data
{
    friend Sales_data add(const Sales_data &,const Sales_data &);
    friend std::ostream &print(std::ostream &,const Sales_data &);
    friend std::istream &read(std::istream &,Sales_data &);

public:
    //�³�Ա������Sales_data����Ĳ���
    string isbn() const{return bookNo;}
    Sales_data &combine(const Sales_data &);  //ģ�¸�ֵ���㣬���������õ�����ֵ����
    double avg_price() const;


private:
    //���ݳ�Ա
    string bookNo;
    unsigned units_sold = 0;  //���������϶�˵��ĳ�Ա�������岻����ֱ�ӳ�ʼ��   ����������
    double revenue = 0;
};

//Sales_data�ķǽӿڳ�Ա����
Sales_data add(const Sales_data &,const Sales_data &);
std::ostream &print(std::ostream &,const Sales_data &);
std::istream &read(std::istream &,Sales_data &);

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;  //��rhs�ĳ�Ա�ӵ�this����ĳ�Ա��
    revenue += rhs.revenue;
    return *this;  //���ص��øú����Ķ���
}

double Sales_data::avg_price() const
{
    double avg = 0;
    avg = revenue / units_sold;
    return avg;
}

std::istream &read(std::istream &is,Sales_data &item)
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main()
{
    Sales_data item;
    read(cin,item);
    print(cout,item);

    return 0;
}
