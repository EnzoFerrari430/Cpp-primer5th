#include <iostream>

int main()
{
    int ival = 1024;
    int &refval = ival;  //refvalָ��ival(��ival����һ������) ival������
    //int &refval2;  �������ñ��뱻��ʼ��
    //int &refval2 = 100;  �������Ҫһ������



    //double pi = 3.14;
    //int &ri = pi;  �����������͵ĳ�ʼֵ������int�Ͷ���

    refval = 2;
    int ii = refval;

    int &refval3 = refval;  //��ȷrefval3�󶨵����Ǹ���refval�󶨵Ķ����Ͼ���ival��
    int i = refval;  //��ȷ��i����ʼ��Ϊival��ֵ

    /*
    std::cout<<"ival "<<ival<<std::endl;

    std::cout<<"refval "<<refval<<std::endl;
    std::cout<<"ii "<<ii<<std::endl;
    */


    return 0;
}
