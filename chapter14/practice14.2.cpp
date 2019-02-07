#include <iostream>
#include <string>
#include <vector>
#include <ostream>
using namespace std;

struct Sales_data
{
    //�³�Ա������Sales_data����Ĳ���
    string isbn() const{return bookNo;}
    //�ڳ�Ա�����ڲ������ǿ���ֱ��ʹ�õ��øú����Ķ���ĳ�Ա��������ͨ�������������������һ��
    //isbn��ʽ��ʹ��thisָ���Ա �൱�� return this->bookNo;
    //����ú����Ķ���ĵ�ַ��ʼ��this

    //�����б�֮���const�ؼ���,������������޸���ʽthisָ�������
    //Ĭ�������this��������ָ�������ͷǳ����汾�ĳ���ָ��
    //��Sales_data��Ա�����У�this��������Sales_data *const  this����ĵ�ַ���ܸģ�����*this���Ը�.
    //������Ĭ�������thisָ�벻�ܰ󶨵�һ������������
    //����Ҫ��thisָ�������� const Sales_data *const������ߺ����������
    //��Ϊthis���ڲ����б��У�����C++�﷨�����const�ؼ��ַ��ڳ�Ա�����Ĳ����б�֮��
    //����this�ͳ���ָ������ָ�룬����isbn���Զ�ȡ���Ķ���ĳ�Ա ���ǲ���д����ֵ
    //�����const�����ж�

    Sales_data &combine(const Sales_data &);  //ģ�¸�ֵ���㣬���������õ�����ֵ����
    inline double avg_price() const;

    //practice 14.2
    //���ϸ�ֵ�����һ���ǳ�Ա����
    Sales_data& operator+=(const Sales_data&);  //���ﷵ����ֵ,���ֳ־���
    friend ostream& operator<<(ostream& output,const Sales_data &s);  //��Ԫ����
    friend istream& operator>>(istream& input,Sales_data &s);
    friend Sales_data operator+(const Sales_data&,const Sales_data&);  //�ӷ��Ͳ�Ӧ�÷�����ֵ

    //���ݳ�Ա
    string bookNo;
    unsigned units_sold = 0;  //���������϶�˵��ĳ�Ա�������岻����ֱ�ӳ�ʼ��   ����������
    double revenue = 0;
};

inline double Sales_data::avg_price()const
{
    return  units_sold? revenue / units_sold : 0;
}


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

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    //bookNo����
    return *this;
}

ostream& operator<<(ostream &output,Sales_data& s)
{
    output<<s.isbn()<<" "<<s.units_sold<<" "<<s.revenue<<" "<<s.avg_price();
    return output;
}

istream& operator>>(istream& input,Sales_data &s)
{
    double price = 0.0;
    input>>s.bookNo>>s.units_sold>>price;
    if(input)
    {
        s.revenue = price * s.units_sold;
    }
    else
    {
        s = Sales_data();
    }
    return input;
}

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;  //���� operator+=
    return sum;
}

int main()
{
    const int a = 42;
    const int *p = &a;



    return 0;
}
