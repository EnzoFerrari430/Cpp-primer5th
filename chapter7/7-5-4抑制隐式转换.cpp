#include <iostream>
#include <string>
using namespace std;
/*
    ����ͨ�������캯������Ϊexplicit��ֹ��ʽת��

    �ؼ���explicitֻ��һ��ʵ�εĹ��캯����Ч����Ҫ���ʵ�εĹ��캯����������ִ����ʽת��

    ֻ���������������캯��ʱʹ��explicit�ؼ��֣����ⲿ����ʱ��Ӧ�ظ�
*/
class Sales_data
{
public:
    Sales_data() = default;
    Sales_data(const string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
    explicit Sales_data(const string &s):bookNo(s){}
    explicit Sales_data(istream&);
    bool isSame(const Sales_data &r)
    {
        return bookNo == r.bookNo;
    }
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

int main()
{
    Sales_data itema("aaa");
    //itema.isSame(string("bbb"));  ����explicit����ֹ��stringת��Sales_data��
    itema.isSame(Sales_data("ccc"));  //���ǿ�����ʽ�Ĺ���һ��Sales_data����

    return 0;
}
