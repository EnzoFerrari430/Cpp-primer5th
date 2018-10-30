#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

template<class T>

void printtemp(T a)
{
    cout<<typeid(a).name()<<endl;
}
int main()
{
    /*
        ������ǿ������ת��
            cast-name<type>(expression);
            type:ת��Ŀ��
            expression:Ҫת����ֵ
            cast-name:
                static_cast(�������ײ�const������  ָ��ָ��Ķ����ǳ���)
                dynamic_cast
                const_cast
                reinterpret_cast

    ��ǿ������ת��˵���������ĳ�����ȱ�ݣ�Ҫ����ʹ��
    */
    double pi = 3.1415;
    int i = pi;

    const int j = 10;

    //void* ���Դ���������͵�ָ��  �κηǳ�������ĵ�ַ���ܴ���void*
    void *p = &i;

    //cout<<*p<<endl;  void* �ܽ����κ����͵�ָ�룬��������û������
    printtemp(i);
    printtemp(pi);
    printtemp(p);
    printtemp(static_cast<int>(pi));  //��ʱת�������ı䱾������
    printtemp(pi);
    double *dp = static_cast<double*>(p);  //��ֻ��������ǿתһ��,������Pv
    printtemp(p);

    //const char *c;
    //char *const d;  ��������ʱ���һ��Ҫ��ʼ��

    const char *cp;
    //char *q = static_cast<char*>(cp);  static_cast����ת����const����
    static_cast<string>(cp);  //�ַ�������ֵת����string����
    return 0;
}
