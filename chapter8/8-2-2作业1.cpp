#include <iostream>
#include <fstream>
using namespace std;

struct Sales_data
{
    //�³�Ա������Sales_data����Ĳ���
    string isbn() const
    {
        return bookNo;
    }

    Sales_data &combine(const Sales_data &);  //ģ�¸�ֵ���㣬���������õ�����ֵ����
    double avg_price() const;

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

std::istream &read(std::istream &is,Sales_data &item)
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price * item.units_sold;
    return is;
}

double Sales_data::avg_price() const
{
    double avg = 0;
    avg = revenue / units_sold;
    return avg;
}

std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}

int main(int argc,char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);

    Sales_data total;
    if(read(input,total))
    {
        Sales_data trans;
        while(read(input,trans))
        {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output,total)<<endl;
                total = trans;
            }
        }
        print(output,total)<<endl;
    }
    else
    {
        cerr<<"No data!"<<endl;
    }


    return 0;
}
