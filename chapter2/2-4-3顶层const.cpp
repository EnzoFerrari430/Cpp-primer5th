#include <iostream>
#include <stdio.h>
/*
    ����const��ʾָ�뱾����һ������
    �ײ�const��ʾָ����ָ�Ķ�����һ������

*/
int main()
{
    int i = 0;
    int *const p1 = &i;  //����const p1��ֵ���ܸı�
    const int ci = 42;   //����const ���Ա�ʾ����Ķ����ǳ���
    const int *p2 = &ci; //����ı�p2��ֵ������һ���ײ�const
    const int *const p3 = p2;  //��һ��const��һ���ײ�const �ڶ���const��һ������const
    //const int *const p3 = &i;
    const int &r = ci;   //�����������õĶ��ǵײ�const  const��r֮�仹��һ��&��

    //��ִ�ж���Ŀ�������ʱ������const����Ӱ��
    i = ci;
    //ci = i
    p2 = p3;  //ָ������������ͬ  ����const��Ӱ��

    //�ײ�const�����ƣ�ִ�ж���Ŀ�������ʱ������Ϳ����Ķ�����������ͬ�ĵײ�const�ʸ�
    //��������������������ͱ����ܹ�ת��,һ��ǳ�������ת���ɳ���
    //int *p = p3;  ��������ת���ɷǳ���
    p2 = p3;
    p2 = &i;  //��ȷ���ǳ�������ת���ɳ���
    //int &r = ci; ��������ת���ɷǳ���
    const int &r2 = i;  //��ȷ���ǳ�������ת���ɳ���


    return 0;
}
