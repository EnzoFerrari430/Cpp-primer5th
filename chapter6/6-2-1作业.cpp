#include <iostream>
using namespace std;
void SwapData(int *p1,int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;  //ָ���βΡ� ָ����ָ�����ֵ�����ı䣬����ʵ�α���û�иı�
    *p2 = temp;
}

void SwapInt(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a1,a2;
    a1 = 42;
    a2 = 21;
    cout<<&a1<<' '<<&a2<<endl;
    SwapData(&a1,&a2);
    cout<<&a1<<' '<<&a2<<endl;  //ָ���βΡ� ָ����ָ�����ֵ�����ı䣬����ʵ�α���û�иı�
    cout<<a1<<' '<<a2<<endl;

    SwapInt(a1,a2);  //�ﺯ�����β��������в���������Ӱ��ʵ��
    cout<<a1<<' '<<a2<<endl;

    return 0;
}
