/*
    ���Ϸ�,��2�ֺ�ѡ��ʽ
    1.operator+(int , double)
        ��siת����int
    2.friend SmallInt operator+(const SmallInt &,const SmallInt &);
        ��3.14ת����int��Ȼ����һ����ʱ����

*/

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
int main()
{
    SmallInt s1;
    //double d = s1 + 3.14;
    double d = s1 + SmallInt(3.14);
    cout<<d<<endl;

    return 0;
}
