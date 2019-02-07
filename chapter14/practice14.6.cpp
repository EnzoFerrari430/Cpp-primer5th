#include <iostream>
#include <string>
using namespace std;
class Sales_data
{

    friend Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);
    friend ostream& operator<<(ostream &,const Sales_data&);
    friend istream& operator>>(istream &,Sales_data & );
public:
    //Sales_data(string s = string(),unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}//6.5.1Ĭ��ʵ������д�������ĳ���βα�������Ĭ��ֵ����������������βζ�������Ĭ��ֵ
    Sales_data():bookNo(""),units_sold(0),revenue(0){}
    Sales_data(string s,unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}
    Sales_data(const Sales_data&);  //�������캯��
    Sales_data& operator=(const Sales_data&);  //������ֵ�����
    Sales_data(Sales_data &&)noexcept;  //�ƶ����캯��
    Sales_data& operator=(Sales_data&&)noexcept;  //�ƶ���ֵ�����
    ~Sales_data() {}
    Sales_data& operator+=(const Sales_data&);

    string isbn()const
    {
        return bookNo;
    }

private:
    inline double avg_price()const;
    //���ݳ�Ա
    string bookNo;
    unsigned int units_sold;
    double revenue;
};

inline double Sales_data::avg_price()const
{
    return units_sold? revenue/units_sold : 0;
}

Sales_data::Sales_data(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
}

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    if( this != &rhs )
    {
        bookNo = rhs.bookNo;
        units_sold = rhs.units_sold;
        revenue = rhs.revenue;
    }
    return *this;
}

Sales_data::Sales_data(Sales_data &&rhs)noexcept
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
}

Sales_data& Sales_data::operator=(Sales_data &&rhs)noexcept
{
    if( this != &rhs )
    {
        bookNo = std::move(rhs.bookNo);
        units_sold = rhs.units_sold;
        revenue = rhs.revenue;
    }
    return *this;

}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data ss(lhs);
    ss += rhs;
    return ss;
}

ostream& operator<<(ostream &output,const Sales_data &rhs)
{
    //output<<rhs.isbn()<<" "<<rhs.units_sold<<" "<<rhs.revenue<<" "<<rhs.avg_price();
    output<<rhs.isbn()<<" "<<rhs.units_sold<<" "<<rhs.revenue<<" "<<rhs.avg_price();
    return output;
}

istream& operator>>(istream &input,Sales_data &rhs)
{
    double price;  //����Ҫ��ʼ������Ϊ���ǽ��ȶ����ݵ�price��֮���ʹ����
    input>>rhs.bookNo>>rhs.units_sold>>price;
    if(input )  //����Ƿ�����ɹ�
    {
        rhs.revenue = rhs.units_sold * price;
    }
    else
    {
        rhs = Sales_data();  //����ʧ�ܣ����󱻸���Ĭ�ϵ�״̬
    }
    return input;
}




int main()
{
    Sales_data s1("C++",100,100);
    Sales_data s2("PHP",100,10);
    Sales_data s3("C++",10,80);
    Sales_data s4;
    cin>>s4;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s1+s3<<endl;

    return 0;
}
