#include <iostream>
using namespace std;

/*
    ���������(<<)���Ҳ����ֵΪ0�Ķ�����λ�����������(>>)����Ϊ������������������������ͣ�
    ���������������޷������ͣ���������ֵΪ0�Ķ�����λ��
    ���������������з������ͣ������������Ϊ�ĸ�����ֵΪ0�Ķ�����λ�����ѡ��Ҫ�Ӿ��廷������

*/

int main()
{
    cout<<sizeof(int)<<endl;
    cout<<sizeof(short)<<endl;
    int num = 4;
    char bits = 016;
    cout<<bits<<endl;
    bits = bits<<3;
    cout<<bits<<endl;
    cout<<num<<endl;
    cout<<~num<<endl;
    num = num << 3;
    cout<<num<<endl;

    int data = 31;
    unsigned int data2 = 31;
    cout<<(data>>1)<<endl;
    cout<<(data2>>1)<<endl;

    cout<<(~data)<<endl;

    unsigned char bits2 = 0227;
    cout<<(~bits2)<<endl;




    return 0;
}
