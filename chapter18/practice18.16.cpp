#include <iostream>
using namespace std;

namespace Exercise
{
int ivar = 0;
double dvar = 0;
const int limit = 1000;
}

int ivar = 0;
/*
Exercise�еĳ�Ա����ȫ���������пɼ�
����������ivar��������ivar��ͻ
using Exercise::ivar;
�ں�������dvar������Exercise�е�dvar
using Exercise::dvar;
using Exercise::limit;
*/
/*
using namespace Exercise;
usingָʾһ�㱻�����ǳ���������������������
usingָʾ��Exercise��ivar����ȫ�ֱ���ivar��ͻ
*/
void manip()
{
    //using Exercise::ivar;
    //using Exercise::dvar;
    //using Exercise::limit;
    //using����������:������Ч��Χ��using�����ĵط���ʼ��һֱ��using�������ڵ�������Ϊֹ��
    //�ڴ˹����У�����������ͬ��ʵ�彫������,  �����������ɶ�����

    /*
    using namespace Exercise;
    ����Ҳ�ǽ�Exercise�����г�Ա�������ȫ�ֱ���
    ivarҲ�ᷢ����ͻ
    */
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
    cout<< Exercise::ivar <<endl;
    cout<< Exercise::dvar <<endl;
    cout<< Exercise::limit <<endl;
    cout<< ::ivar <<endl;
    cout<< dvar <<endl;
    cout<< iobj <<endl;
}


int main()
{
    manip();

    return 0;
}
