#include <iostream>

using namespace std;
/*
    ������Ԫ��ϵ���ܴ���һ������Ԫ��ϵͬ��Ҳ���ܼ̳�

    �������Ԫ�ڷ����������Աʱ�����������ԣ����Ƶģ����������ԪҲ����������ʻ���ĳ�Ա
*/
class Pal;

class Base
{
    friend class Pal;
protected:
    int prot_mem;  //protected��Ա
};

class Sneaky : public Base
{
    friend void clobber(Sneaky&);  //�ܷ���Sneaky::prot_mem
    friend void clobber(Base&);  //���ܷ���Base::prot_mem
    int j;  //class Ĭ����private��
};

class Pal
{
public:
    int f(Base b){return b.prot_mem;}  //��ȷ Pal��Base����Ԫ
    int f2(Sneaky s){return s.j;}  //����Pal����Sneaky����Ԫ

    //�Ի���ķ���Ȩ���ɻ��౾����ƣ���ʹ����������Ļ��ಿ��Ҳ�����
    int f3(Sneaky s){return s.prot_mem;}  //��ȷ��Pal��Base����Ԫ
};

int main()
{


    return 0;
}
