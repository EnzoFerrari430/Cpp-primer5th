#include <iostream>
using namespace std;


class SmallInt
{
    friend SmallInt operator+(const SmallInt &,const SmallInt &);
public:
    SmallInt(int = 0);  //ת��ԴΪint������ת��
    operator int()const {return val;}  //ת��Ŀ��Ϊint������ת��
private:
    std::size_t val;
};

SmallInt::SmallInt(int a)
{
    val = a;
}

SmallInt operator+(const SmallInt &lhs,const SmallInt &rhs)
{

    return lhs.val + rhs.val;
}


struct LongDouble
{
    //ͨ������� + �Ǹ��ǳ�Ա
    LongDouble operator+(const SmallInt &);
    LongDouble(double = 0.0);
    operator double();
    operator float();

};
LongDouble operator+(LongDouble &,double);
int main()
{
    SmallInt si;
    LongDouble ld;
    ld = si + ld;
    /*
        ��ѡ������
        1.friend SmallInt operator+(const SmallInt &,const SmallInt &);  ldû��תint������ת�������operator+����
        2.��������  operator+(int + float) operator+(int + double) si����ת����int ld����ת����float����double�����������
        3.
    */

    ld = ld + si;
    /*
        ��ѡ������
        1.LongDouble operator+(const SmallInt &);
        2.LongDouble operator+(LongDouble &,double);  siת����int��ת����double
        ��2�ַ�ʽ����ʵ�֣����ǵ�һ���Ǿ�ȷƥ�䣬���ȼ���
    */


    return 0;
}
