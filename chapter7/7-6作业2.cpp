#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Example
{
public:
    static constexpr double rate = 6.5;  //���ڳ�ʼ����̬��Ա��Ҫ��̬��Ա����������ֵ����
    static constexpr int vecSize = 20;
    static vector<double> vec;  //���ڲ���ȷ����С
};

constexpr double Example::rate;  //������ⲿ���徲̬��Աʱ�����ظ�static Ҫ��constexpr
vector<double> Example::vec(Example::vecSize);
int main()
{


    return 0;
}
