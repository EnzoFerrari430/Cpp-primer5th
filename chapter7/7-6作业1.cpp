#include <iostream>
#include <string>
using namespace std;
/*
    7.56 �ó�Աֱ�����౾���йأ�����������ĸ������󱣳ֹ���������ͨ���ڳ�Ա����֮ǰ���Ϲؼ���staticʹ�������������һ��
        �ŵ㣺 ÿ��������Ҫ�洢һ�����������ݣ�������ݸı��ˣ���ÿ��������ʹ���µ�ֵ
        ����ͨ��Ա������1.��̬���ݳ�Ա�����ǲ���ȫ����
                          2.��̬��Ա������ΪĬ��ʵ��
*/

//7.57
class Account
{
public:
    void total(){amount += amount * yearRate;}
    static double rate(){return yearRate;}  //static����������thisָ��    return��yearRate����static��
    static void rate(double newRate){yearRate = newRate;}

private:
    string owner;
    double amount;  //����
    static double yearRate;  //������
    static constexpr double nowRate = 4.33;
    static double initRate(){return nowRate;}

};

//���岢��ʼ��һ����̬��Ա
double Account::yearRate = initRate();





int main()
{


    return 0;
}
