#include <iostream>

/*
����ͨ���ò�ͬ���ǣ��Գ��������ò��ܱ������޸������󶨵Ķ���

���õ����ͱ�����������ö��������һ�µ�����2����������
1.�ڳ�ʼ����������ʱ��������������ʽ��Ϊ��ʼֵ


*/

int main()
{
    const int ci = 1024;
    const int &r1 = ci;  //���ü����Ӧ�Ķ����ǳ���
    //r1 = 42;  //r1�ǶԳ��������ò����޸�ֵ
    //int &r2 = ci;  //�ǳ��������ò���ָ��һ����������


    char c = 42;
    double d = 3.14;
    const int &r3 = c;  //���һ
    /*
        �����������һ����ʱ�����ͳ���,Ȼ������r3�������ʱ��
        const int temp = c;
        const int &r3 = temp;
    */
    const int &r4 = d;
    //int &r5 = d;
    //int &r5 = c;  //������ͨ�ķǳ�������
    std::cout<<r3<<std::endl;
    std::cout<<r4<<std::endl;
    std::cout<<d<<std::endl;

    return 0;
}
