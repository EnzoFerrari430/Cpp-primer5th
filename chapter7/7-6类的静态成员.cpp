#include <iostream>
#include <string>
using namespace std;

//����ͨ���ڳ�Ա������֮ǰ���Ϲؼ���staticʹ�������������һ�𡣺�������Աһ������̬��Ա������public����private
//��̬���ݳ�Ա�����ǳ��������ã�ָ�룬�����͵�

class Account
{
public:
    void calculate(){amount +=amount * interestRate;}  //��Ա��������ͨ�������������������ֱ��ʹ�þ�̬��Ա
    static double rate(){return interestRate;}
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();

    //ͨ����ľ�̬��Ա��Ӧ��������ڲ���ʼ���������ǿ���Ϊ��̬��Ա�ṩconst�������͵����ڳ�ʼֵ
    //����Ҫ��̬��Ա����������ֵ��������constexpr����ʼֵ�����ǳ������ʽ����Щ��Ա���������������ڳ������ʽ�ĵط���
    static constexpr int period = 30;
    double daily_tbl[period];
    //����ó�Ա���ڱ����������������ֵ������£����ʼ��һ��const����constexpr static����Ҫ��������
    //��˼�������period�������ڲ�ʹ�ã���ô����Ͳ��÷��룬���ڳ�ʼ�����㹻�ˣ������������ʹ�ã��ͻ���ֱ������
    //�෴�ģ���ó�Ա������һ���������
};

//����ľ�̬��Ա�������κζ���֮�⣬�����в������κ��뾲̬���ݳ�Ա�йص����ݡ�
//����ÿ��Account���󽫰����������ݳ�Ա��owner��amount��ֻ����һ��interestRate������ұ�����Account������

//���Ƶģ���̬��Ա����Ҳ�����κζ������һ�����ǲ�����thisָ�롣��Ϊ�������̬��Ա��������������const
//������static��������ʹ��thisָ�롣


//�ﾲ̬��Ա�������Զ���������ڲ�Ҳ���Զ���������ⲿ����������ⲿʱ�������ظ�static�ؼ��֣��ùؼ���ֻ���������ڲ����������
void Account::rate(double newRate)
{
    interestRate = newRate;
}

//���岢��ʼ��һ����̬��Ա
//������ ���� ����������� ��Ա�Լ�������
double Account::interestRate = initRate();  //��̬��Ա�����Ķ���Ҳ���Է������˽�г�Ա

//��̬��Ա�����ĵ�ַ���Դ洢��һ������ĺ���ָ���У�������ָ���Ա������ָ����

int main()
{
    //�����������ֱ�ӷ��ʾ�̬��Ա
    double r;
    r = Account::rate();

    //��Ȼ��̬��Ա���������ĳ�����󣬵���������Ȼ����ʹ����Ķ������û���ָ�������ʾ�̬��Ա

    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();

    return 0;
}
