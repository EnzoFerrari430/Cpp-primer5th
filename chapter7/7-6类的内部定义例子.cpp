#include <iostream>

class Account {
public:
    static double GetCircumference(const double& dR) { return 2 * dR * 3.1415926; }
    static constexpr double cd = 3.0;  //���ǿ���Ϊ��̬��Ա�ṩconst�������͵����ڳ�ʼֵ������Ҫ��̬��Ա����������ֵ���͵�constexpr
};
//���cd�������ڲ�ʹ�ã���ô����Ͳ��÷ֱ��壬���ڳ�ʼ�����㹻�ˣ������������ʹ�ã��ͻ���ֱ������
constexpr double Account::cd;  //������������������ֲ�ͬ�Ľ��

int main()
{
    //ʹ�������������ֱ�ӷ��ʾ�̬��Ա
    std::cout << Account::GetCircumference(Account::cd) << std::endl;
    return 0;
}
