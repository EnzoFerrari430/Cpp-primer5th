#include <iostream>
#include <cstdlib>


int main()
{
    int *p1 = nullptr;  //C++11��׼
    int *p2 = 0;
    int *p3 = NULL;

    std::cout<<p1<<std::endl;
    std::cout<<p2<<std::endl;
    std::cout<<p3<<std::endl;

    //void *ָ����Դ���������ĵ�ַ,Ҳ���Դ���������͵�ָ��
    //void *ָ��ֵ�������޵�����,����ֱ�Ӳ���void *ָ����ָ�Ķ���
    double obj = 3.14,*pd = &obj;
    void *pv = &obj;
    pv = pd;


    return 0;
}
