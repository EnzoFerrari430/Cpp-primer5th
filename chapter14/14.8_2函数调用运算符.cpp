#include <iostream>
using namespace std;


struct A
{
public:
    void operator()(){cout<<"hellow orld"<<endl;}
};

int main()
{


    A()();  //A()  ������һ����ʱ����Ȼ���ٵ��� �������������
    return 0;
}
