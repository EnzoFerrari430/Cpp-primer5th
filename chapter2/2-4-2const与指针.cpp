#include <iostream>

int main()
{
/*
    ָ������ָ��(pointer to const)�������ڸı�����ָ�����ֵ
    ��Ҫ��ų�������ĵ�ַ��ֻ��ʹ��ָ������ָ��

    ���ָ������Ϊָ����ǳ���,�����ǲ��ǳ�������Ҫ��ָ��Ķ���ԭ���ǲ��ǳ���
*/
    const double pi = 3.14;  //pi�ǳ������ܸı�
    //double *ptr = &pi;  //���� ptr��һ����ָͨ��
    const double *cptr = &pi;  //��ȷ��cptr����ָ��һ��˫���ȳ���
    // *cptr�ǳ��� ����cptr���ǳ������Ըı�
    //*cptr = 42;
    std::cout<<pi<<std::endl;
    std::cout<<*cptr<<std::endl;
    std::cout<<cptr<<std::endl;
    cptr += 1;
    std::cout<<pi<<std::endl;
    std::cout<<*cptr<<std::endl;
    std::cout<<cptr<<std::endl;

/*
ָ������ͱ���������ָ���������һ��
������2������
1.������һ��ָ������ָ��ָ��һ���ǳ�������

*/
    double dval = 3.1415;
    const double *rd = &dval;  //��ͨ�����ǲ�����rdָ��ı�dval��ֵ
    //const int *rd2 = &dval;  //���Ͳ���
    //*rd = 3.1;  wrong
    dval = 3.1;  //right
    std::cout<<dval<<std::endl;
    std::cout<<*rd<<std::endl;

    rd = rd+1;
    std::cout<<*rd<<std::endl;
    rd = rd+1;
    std::cout<<*rd<<std::endl;





    return 0;
}
