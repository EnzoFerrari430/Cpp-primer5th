#include <iostream>

int main()
{
    //std::cout<<sizeof('a')<<std::endl;  //1
    //std::cout<<sizeof("a")<<std::endl;  //2 �����\0

    /*
        ͨ��*�ĸ�����������ָ��ļ���
        **��ʾָ��ָ���ָ�� 2��ָ��
        ***��ʾָ��ָ���ָ���ָ��  3��ָ��...

    */
    int ival = 1024;
    int *pi = &ival; //ָ��һ��int�͵���
    int **ppi = &pi; //ָ��һ��int�͵�ָ��

    std::cout<<"the value of ival\n"
    <<"direct value: "<<ival<<"\n"
    <<"indirect value: "<<*pi<<"\n"
    <<"double indirect value: "<<**ppi<<std::endl;

    std::cout<<pi<<std::endl;
    std::cout<<ppi<<std::endl;



    return 0;
}
