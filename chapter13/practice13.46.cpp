#include <iostream>
#include <vector>
using namespace std;


int f();

int f()
{
    return 1;
}


vector<int> vi(100);


int &&r1 = f();  //  f()  ���ص�����ʱ��int  ��������ֵ
int &r2 = vi[0];  //�������־�  ��������ֵ
int &r3 = r1;  //  r1��һ���־õĶ���  ��������ֵ
int &&r4 = vi[0] * f();  //  vi[0] * f() ֮�������������һ������ֵ����  ��������ֵ
//��򵥵��жϷ�������������ܲ��������Լ���

//13.47��13.44�Ĵ�


int main()
{
    cout<<vi[0]<<endl;

    return 0;
}
