/*

    ���ص������Ҳ�����صĺ����� һ�������operator+ �ǳ�Ա����Ҳ��������Ԫ���� ��������� ��
    ����㶨���˳�Ա����operator+����Ԫ����operator+���������ʽ�����ֲ���������õ��ǳ�Ա�������Ƿǳ�Ա����
    a+b�����ֲ����ǵ��ó�Ա����������Ԫ����
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
    SmallInt s1,s2;
    SmallInt s3 = s1 + s2;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    //int i = s3 + 0;  //�����Դ���
    //  1.���ǿ��԰�0ת����SmallInt��Ȼ��ʹ��SmallInt��+
    //  2.����Ҳ���԰�s3ת����intȻ���2��intִ�����õļӷ�����
    SmallInt s4(3.14);
    cout<<s4<<endl;


    return 0;
}
