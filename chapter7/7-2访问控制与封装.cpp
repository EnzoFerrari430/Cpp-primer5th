#include <iostream>
#include <string>
#include <vector>
using namespace std;
//public˵����֮��ĳ�Ա�����������ڿɱ����ʣ�public��Ա������Ľӿ�
//private˵����֮��ĳ�Ա���Ա���ĳ�Ա��������,���ǲ��ܱ�����Ĵ�����ʣ�private���ַ�װ���ʵ��ϸ��
class Sales_data
{
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

int main()
{


    return 0;
}
