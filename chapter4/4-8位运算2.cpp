#include <iostream>
using namespace std;


/*
    λ���:��Ӧλ���ϵ�ֵ����ͬ�������1��������0
    ��λ����������ȼ�����Ҳ���ͣ���������������ȼ��� �ȹ�ϵ���������ֵ�������������������ȼ���
*/

int main()
{
    int i,j;
    i = 0;
    j = 1;

    cout<<(i^j)<<endl;

    //��Щ������unsigned int���ȴﲻ��16λ
    unsigned long quiz1 = 0;
    //1ul ����ֵ��1��unsigned long����
    quiz1 |= 1ul << 27;  //ѧ��27ͨ���˲���
    cout<<quiz1<<endl;

    quiz1 &= ~(1ul << 27);  //ѧ��27û��ͨ������
    cout<<quiz1<<endl;

    bool status = quiz1 & (1ul << 27); //ѧ��27��û��ͨ������
    cout<<status<<endl;



    return 0;
}
