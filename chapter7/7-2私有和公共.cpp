#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A():a1(100),a2(200)
    {
        a1 = 1;
        a2 = 2;
        a3 = 3;
        a = 4;
    }
    void fun()
    {
        cout<<a<<endl;
        cout<<a1<<endl;
        cout<<a2<<endl;
        cout<<a3<<endl;
    }
    A add()
    {
        //��Ա����ͨ��һ����Ϊthis�Ķ�����ʽ���������ʵ��������Ǹ�����
        ++a3;
        //return a3;
        return *this;
    }
public:
    int a1;
protected:
    int a2;
private:
    int a3;
};

int main()
{
    A itema;
    itema.a = 10;
    itema.a1 = 20;
    //itema.a2 = 30;  ���ⲻ�ܷ���protected��Ա
    //itema.a3 = 40;  ���ⲻ�ܷ���private��Ա
    itema.fun();
    A itemb = itema.add();
    itema.fun();
    itemb.fun();
    A itemc;
    itemc.fun();

    return 0;
}
