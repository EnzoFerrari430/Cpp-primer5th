#include <iostream>

int main()
{
    int ival = 42;
    int *p = &ival;
    //int &refval = ival;
    //int *pp = &refval;  ���ò��Ƕ���û��ʵ�ʵĵ�ֵַ�����Բ��ܶ���ָ�����õ�ָ��
    std::cout<<*p<<std::endl;  //*�ǽ����÷� �ɷ���*�õ�ָ��p��ָ�Ķ���
    std::cout<<p<<std::endl;
    *p = 10;  //�ɷ���*�õ�ָ��p��ָ�Ķ��󣬿ɾ���pΪ����ival��ֵ
    std::cout<<ival<<std::endl;


    double dval = 3.14;
    double *pd = &dval;
    double *pd2 = pd;  //��ʼֵ��ָ��double�����ָ�룬pd��������dval�ĵ�ַ
    double **pd3 = &pd;

    //int *pi = pd;  //ָ��pi�����ͺ�pd��ƥ��
    //pi = &dval;  //double�Ͷ���ĵ�ַ���ܸ�ֵ��int��ָ��

    std::cout<<pd<<" "<<*pd<<std::endl;
    std::cout<<pd2<<" "<<*pd2<<std::endl;
    std::cout<<pd2<<" "<<&pd2<<std::endl;
    std::cout<<pd3<<" "<<**pd3<<std::endl;



    return 0;
}
