#include <iostream>
#include <string>
using namespace std;
//��̬��Ա�������κζ���
//���Ծ�̬���ݳ�Ա�����ǲ���ȫ���ͣ����Ǿ�̬���ݳ�Ա���ܵ����ƣ�ֻ�����������������ָ���������

class Bar
{
public:
    //
private:
    static Bar men1;
    Bar *men2;
    //Bar men3;  //error men3�������ǲ���ȫ��
};

//�����һ�����𣬾�̬��Ա������ΪĬ��ʵ��
class Screen
{
public:
    //bkground��ʾһ���������Ժ���ľ�̬��Ա
    Screen &clear(char = bkground);
private:
    static const char bkground;
};
//�Ǿ�̬���ݳ�Ա������ΪĬ��ʵ�Σ���Ϊ����ֵ�������ڶ����һ���֣���ô���Ľ�����޷������ṩһ�������Ա���л�ȡ��Ա��ֵ�����ս���������


int main()
{


    return 0;
}
