#include <iostream>
/*
����const ��ʾָ�뱾���Ǹ�����

�ײ�const ��ʾָ����ָ�Ķ�����һ��const


*/



int main()
{
    //int i, *const cp;  constָ��һ��Ҫ��ʼ��
    //����һ��int�͵�i ��int�͵�constָ�룬����cpû�г�ʼ��

    //int *p1,*const p2;  ͬ��constָ��һ��Ҫ��ʼ��

    //const int ic,&r = ic;  const int ic��icһ��Ҫ��ʼ��

    //const int *const p3;  constָ��һ��Ҫ��ʼ��

    //const int *p;  //�ɹ�

    /*
    const int ic = 42;
    int *p1;
    p1 = &ic;
    wrong  ic��const int��ָ�벻����int * Ӧ����const int *p1
    */

    /*
    const int ic = 42;
    const int *const p3 = &ic;
    �ɹ�
    */

    /*
    const int ic = 42;
    const int *const p3;
    ic = *p3;
    p3��Ҫ��ʼ�� ����ic��ֵ���ܸı�
    */

    return 0;
}
