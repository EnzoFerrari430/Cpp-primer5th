#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

#include <iostream>
#include <string>
class Sales_data
{
public:

    friend Sales_data operator-(const Sales_data &,const Sales_data &);
    friend Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);
    friend std::ostream& operator<<(std::ostream &,const Sales_data&);
    friend std::istream& operator>>(std::istream &,Sales_data & );
    friend bool operator==(const Sales_data &,const Sales_data &);  //14.3.1��������
    friend bool operator!=(const Sales_data &,const Sales_data &);
public:
    //Sales_data(string s = string(),unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}//6.5.1Ĭ��ʵ������д�������ĳ���βα�������Ĭ��ֵ����������������βζ�������Ĭ��ֵ
    Sales_data(std::string s,unsigned int u,double price):bookNo(s),units_sold(u),revenue( u * price ) {}
    Sales_data():bookNo(""),units_sold(0),revenue(0){}
    Sales_data(const std::string &s):Sales_data(s,0,0.0f){}
//    Sales_data(const Sales_data&);  //�������캯��
//    Sales_data& operator=(const Sales_data&);  //������ֵ�����
//    Sales_data(Sales_data &&)noexcept;  //�ƶ����캯��
//    Sales_data& operator=(Sales_data&&)noexcept;  //�ƶ���ֵ�����
    ~Sales_data() {}
    Sales_data& operator+=(const Sales_data&);  //14.4���ϸ�ֵ�����
    Sales_data& operator-=(const Sales_data&);

    Sales_data& operator=(const std::string &);

    std::string isbn()const
    {
        return bookNo;
    }

    //practice14.45
    explicit operator std::string()const{return bookNo;}
    explicit operator double()const{return revenue;}
    //practice14.46  ����һ�����õ�ע�⣬��ΪSales_dataֻ��3��������һ��ʱ������Ч�����ݣ����Ҫ�ӵĻ�һ��Ҫ��explicit��ֹ������ʽת��
private:
    inline double avg_price()const;
    //���ݳ�Ա
    std::string bookNo;
    unsigned int units_sold;
    double revenue;
};
Sales_data operator-(const Sales_data &,const Sales_data &);
Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);
std::ostream& operator<<(std::ostream &,const Sales_data&);
std::istream& operator>>(std::istream &,Sales_data & );
bool operator==(const Sales_data &,const Sales_data &);
bool operator!=(const Sales_data &,const Sales_data &);

inline double Sales_data::avg_price() const
{
    return units_sold?  revenue / units_sold : 0;
}

template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}

#endif // SALES_DATA_H_INCLUDED
