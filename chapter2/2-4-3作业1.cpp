#include <iostream>

int main()
{
    int i = 0;
    const int v2 = 0;  //����const
    int v1 = v2;  //����const������������
    int *p1 = &v1,&r1 = v1;  //���Ƿǳ���
    const int *p2 = &v2;  //v2��һ������const ���Բ�Ӱ��
    const int *const p3 = &i;  //i��һ���ǳ���
    const int &r2 = v2;  //�ײ�const��֧�ַǳ���ת���ɳ���


    r1 = v2;  //��ȷ,r1��v1�����ã�v2�Ƕ���const
    //p1 = p2;  //����,p2��һ���ײ�const����֧�ִӳ���ת����Ϊ�ǳ���
    p2 = p1;  //��ȷ,p2��һ���ײ�const��p1�Ƿǳ�����֧�ִӷǳ���ת���ɳ���
    //p1 = p3;  //����,p3����һ���ײ�const p1�Ƿǳ�������֧�ִӳ���ת���ɷǳ���
    p2 = p3;  //��ȷ��2�����ǵײ�const

    return 0;
}
