#include <iostream>

int main()
{
    //a
    //int i = -1,&r = 0;  ���� &r�����ڶ����ʱ������ʼ�������ҳ�ʼ��һ����һ������

    //c
    const int i = -1,&r = 0;

    //b
    int i2;
    int *const p2 = &i2;

    //d
    const int *const p3 = &i2;

    //e
    const int *p1 = &i2;  //�����ڶ����ʱ���Ҫ��ʼ��

    //f
    //int ii = 0;
    //const int &const r2 = ii;  //���ñ����ʼ�� ����const���������÷���&����Ϊ���ò���һ������

    //g
    const int i3 = i,&r1 = i;  //right r1Ҳ��һ��const������

    //int const *p = &i;

    //const int const *p4 = &i2;  VS2008ͨ��

    return 0;
}
