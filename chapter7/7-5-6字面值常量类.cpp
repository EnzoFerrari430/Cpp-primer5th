#include <iostream>
using namespace std;
/*
    ���ݳ�Ա��������ֵ���͵ľۺ���������ֵ������

    ������Ǿۺ��൫��������������Ҳ������ֵ������
        1.���ݳ�Ա������������ֵ����
        2.��������ٺ���һ��constexpr���캯��
        3.���һ�����ݳ�Ա�������ڳ�ʼֵ�����������ͳ�Ա�ĳ�ʼֵ������һ���������ʽ��
            ���������Ա����ĳ�������ͣ����ʼֵ����ʹ�ó�Ա�Լ���constexpr���캯��
        4.�����ʹ������������Ĭ�϶��壬�ó�Ա����������Ķ���

    ���ܹ��캯��������const����������ֵ������Ĺ��캯��������constexpr������in factһ������ֵ��������������ṩ��һ��constexpr���캯��

    constexpr����Ҫ�� ����ӵ��Ψһ��ִ�������Ƿ�����䣬���ǹ��캯���������з�����䡣
    ����constexpr���캯��һ����ǿյĺ�����

    constexpr���캯�������ʼ���������ݳ�Ա����ʼֵ����ʹ��constexpr���캯����������һ���������ʽ

    constexpr���캯����������constexpr�����Լ�constexpr�����Ĳ������߷������ͣ�
*/
class Debug
{
public:
    constexpr Debug(bool b = true):hw(b),io(b),other(b){}
    constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}
    constexpr bool any() {return hw || io || other;}

    void set_io(bool b){io = b;}
    void set_hw(bool b){hw = b;}
    void set_other(bool b){hw = b;}
private:
    bool hw;
    bool io;
    bool other;
};



int main()
{
    return 0;
}
