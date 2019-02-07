#include <iostream>
#include <ostream>
#include <istream>
using namespace std;
/*
    oop(�������������)�ĺ���˼���ǣ����ݳ��󣬼̳кͶ�̬��
*/
//�̳У����ฺ�����ڲ�ι�ϵ�������๲ͬӵ�еĳ�Ա����ÿ�������ඨ��������еĳ�Ա

//����һ��Quote�࣬������Ϊ��ι�ϵ�еĻ��࣬Quote�Ķ����ʾ��ԭ�����۵��鼮
//Quote����������һ����ΪBulk_quote�࣬��ʾ���Դ��۳��۵��鼮
/*
    ��Щ���������������Ա����
    isbn(),�����鼮��ibsn��š��ò������漰������������ԣ����ֻ������Quote���С�
    net_price(size_t)�������鼮��ʵ�����ۼ۸�ǰ�����û��������������ﵽһ����׼�����������Ȼ���������йصģ�Quote��Bulk_quote��Ӧ�ð����ú���
*/
class Quote
{
public:
    std::string isbn()const;
    virtual double net_price(std::size_t n)const;
};

//���������ͨ��ʹ���������б���ȷָ�����Լ��Ǵ��ĸ�����Щ������̳ж������������б���ʽ��  ������һ��ð�ţ���������Զ��ŷָ��Ļ����б�ÿ������ǰ����з���˵����
class Bulk_quote : public Quote
{
public:
    virtual double net_price(std::size_t n)const override;  //virtual�ɼӿɲ��ӣ�override��C++11�����Դ�����ע���ó�Ա������д�˻�����麯��
};

//��̬�󶨣�������ͬһ�δ���ֱ���Quote��Bulk_quote�Ķ���
//���㲢��ӡ���۸���������ĳ���鼮���õķ���
double print_total( ostream &os,const Quote &item,size_t n )
{
    //���ݴ���item�βεĶ������͵���Quote::net_price����Bulk_quote::net_price
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}
//�������������а汾��ʵ�ξ�������������ʱѡ�����İ汾�����Զ�̬����ʱ�ֱ���Ϊ����ʱ�󶨡�

//  ����������ʹ�û�������û�ָ�����һ���麯��ʱ��������̬�󶨡�


int main()
{


    return 0;
}
