#include <iostream>
/*
ָ������ò�ͬ��ָ��ʹ�������ò��ǣ����������ָ�뱾��λ����
**����ָ������ʼ��
һ����ʼ����ɣ�����ֵ(�����ָ���е��Ǹ���ַ)�Ͳ��ܸı���
��*����const֮ǰ˵��ָ����һ������


*/


int main()
{
    int errNumb = 0;
    int *const curErr = &errNumb;  //���ָ��һֱָ��errNumb,���ָ����һ��ֻ���ı���
    //curErr�ǳ������� *curErr���ǳ��� ���Ըı�


    std::cout<<*curErr<<std::endl;
    *curErr = *curErr + 1;  //���ǿ����ù�curErrָ��ı�errNumbֵ
    std::cout<<*curErr<<std::endl;


    const double pi = 3.14159;
    const double *const pip = &pi;  //pip��ָ��������ĳ���ָ��



    return 0;
}
