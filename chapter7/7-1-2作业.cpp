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

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    Sales_data total;
    if(cin>>total.bookNo>>total.units_sold>>total.revenue)
    {
        Sales_data trans;
        while(cin>>trans.bookNo>>trans.units_sold>>trans.revenue)
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout<<total.bookNo<<' '<<total.units_sold<<' '<<total.revenue<<endl;
                total = trans;
            }
        }
        cout<<total.bookNo<<' '<<total.units_sold<<' '<<total.revenue<<endl;
    }
    else
    {
        cerr<<"no data!"<<endl;
    }
    return 0;
}
