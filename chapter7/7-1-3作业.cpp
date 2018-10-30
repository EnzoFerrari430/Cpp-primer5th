#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Sales_data
{
    string isbn() const
    {
        return bookNo;
    }
    Sales_data &combine(const Sales_data &);  //ģ�¸�ֵ���㣬���������õ�����ֵ����
    double avg_price() const;

    //���ݳ�Ա
    string bookNo;
    unsigned units_sold;  //���������϶�˵��ĳ�Ա�������岻����ֱ�ӳ�ʼ��   ����������
    double revenue;
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

std::istream &read(std::istream &is,Sales_data &item)  //��ͨ���ã���ΪҪ���������д��ֵ
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item)  //�������ã�ֻ��Ҫ��ȡ������� ����Ҫд����
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
    Sales_data total;
    if(read(cin,total))
    {
        Sales_data trans;
        while(read(cin,trans))
        {
            if(total.isbn() == trans.isbn())
            {
                add(total,trans);
            }
            else
            {
                print(cout,total);
                total = trans;
            }
        }
        cout<<total.isbn()<<" "<<total.units_sold<<" "<<total.revenue<<" "<<total.avg_price();
    }
    else
    {
        cerr<<"no data!"<<endl;
    }
    return 0;
}
