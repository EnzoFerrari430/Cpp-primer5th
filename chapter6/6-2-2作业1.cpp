#include <iostream>
using namespace std;
void SwapData(int &i1,int &i2)
{
    int temp;
    temp = i1;
    i1 = i2;
    i2 = temp;
}
int main()
{
    int a1 = 30;
    int a2 = 15;
    SwapData(a1,a2);
    cout<<a1<<' '<<a2<<endl;

    /*
        6.13
        void f(T) ������T�Ĳ�������Ӱ��ʵ��
        void f(&T) T��ʵ�ΰ�����������ʵ��
        6.14
        �����Ҫ�޸�ʵ�Σ��Ϳ���������
        6.15
        string ����ĳ��ȿ��ܻ�ǳ�����Ҫ����ֱ�ӿ������ǣ�����string��������ı䣬������const
        occurs��Ҫ������¼�ַ�c���ֵ��ַ����ᷢ���ı䣬��������ͨ����
        cֻ��һ����ʱ�����������޸ġ�
    */

    return 0;
}
