#include <iostream>
using namespace std;

/*
    ������������һ����������Ҳ�����¶�������ֱ�ӻ�����ӻ����е����֡�
    ��ʱ�����ࣨ�ڲ������򣩵����ֽ����ض����ڻ��ࣨ��������򣩵����֡�
*/
class Base
{
public:
    Base() : mem(0){}
protected:
    int mem;
};

class Derived : public Base
{
public:
    Derived(int i):mem(i){}
    int get_mem()const{return mem;}
    int get_base_mem()const{return Base::mem;}  //����ͨ���������������ʹ��һ�������صĻ����Ա
protected:
    int mem;  //���ػ����е�mem
};

int main()
{
    Derived d(42);
    cout<<d.get_mem()<<endl;

    //����������������ǵ�ԭ�еĲ��ҹ��򣬲�ָʾ��������Base���������ʼ����mem
    cout<<d.get_base_mem()<<endl;

    return 0;
}
