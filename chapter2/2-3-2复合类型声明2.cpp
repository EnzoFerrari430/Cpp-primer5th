#include <iostream>

int main()
{
    int i = 42;
    int *p;  //p��int��ָ��
    int *&r = p;  //r��һ����ָ��p������
    //int *&r ���������Ķ� ��r�������& ���r��һ�����ã�*��ʾr���õ���һ��ָ�룬���int˵��r���õ���һ��int��ָ��

    r = &i;  //r������һ��ָ�룬��˸�r��ֵ&i�����ǽ�pָ��i
    *r = 0; //ʹ�ý����÷���* �õ�i��i��ֵ��Ϊ0

    std::cout<<i<<std::endl;  //0
    std::cout<<*p<<std::endl; //0
    std::cout<<*r<<std::endl; //0

    const int buf = 512;
    //buf = 100;  const�޶����Ĳ��ܸı�

    //const int c = get_size();

    return 0;
}
