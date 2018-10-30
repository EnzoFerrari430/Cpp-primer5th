#include <iostream>
#include <string>
#include <typeinfo>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    int ia[3][4] = {0};
    int (*p)[4] = ia;  //p��һ��ָ�� ָ����4������������
    p = &ia[2];  //pָ��ia��βԪ��
    /*
        int *ip[4];  ����ָ�������
        int (*ip)[4];  ָ����4��������ָ��

        ʹ��C++11�±�׼�����auto decltype���ܾ����ܱ���������ǰ�����һ��ָ��������
    */

    /*
        ʹ�����ͱ���Ҳ�ܼ򻯶�ά�����ָ��
    */

    //��4��������ɵ���������Ϊint_array
    using int_array = int[4];  //�±�׼�µ����ͱ�������
    cout<<typeid(int_array).name()<<endl;  //A4_i
    typedef int int_array[4];  //�ȼ۵�typedef����
    //���Ԫ��
    for(int_array *p = ia;p != ia+3; p++)
    {
        for(int *q = *p;q != *p +4;q++)
        {
            cout<<*q<<' ';
        }
        cout<<endl;
    }

    return 0;
}
