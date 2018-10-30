#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�����������������ߺ����������ķǹ��г�Ա������������������ߺ�����Ϊ������Ԫ
//��������һ��������Ϊ������Ԫ��ֻ������һ����friend�ؼ��ֿ�ͷ�ĺ����������
class Sales_data
{
    //  ΪSales_data�ķǳ�Ա������������Ԫ����

    friend Sales_data add(const Sales_data &,const Sales_data &);
    friend std::istream &read(std::istream &,Sales_data &);
    friend std::ostream &print(std::ostream &,const Sales_data &);

public:  //���ʿ���˵����
    Sales_data() = default;
    Sales_data(const string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(const string &s):bookNo(s){}
    Sales_data(istream &);
    string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &);
private:  //���ʿ���˵����
    double avg_price() const {return units_sold? revenue / units_sold:0;}
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
//��Ϊ�ӿڣ����캯���Ͳ��ֳ�Ա����������public˵����֮��
//�����ݳ�Ա����Ϊʵ�ֲ��ֵĺ��������private˵��������

/*
    class��struct������
    struct��class��Ĭ�Ϸ���Ȩ�޲�̫һ��
    ����������ĵ�һ������˵����֮ǰ�����Ա�������ֳ�Ա�ķ���Ȩ����������Ķ��塣
        ���ʹ�õ���struct�ؼ��֣������ڵ�һ������˵����֮ǰ�ĳ�Ա��public���෴�ģ����ʹ��class�ؼ��֣�����Щ��Ա��private
*/

Sales_data add(const Sales_data &,const Sales_data &);
std::istream &read(std::istream &,Sales_data &);  //IO�����ڲ��ܱ����������ͣ����ֻ��ͨ����������������
std::ostream &print(std::ostream &,const Sales_data &);

int main()
{


    return 0;
}
