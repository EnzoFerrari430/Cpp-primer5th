#include <iostream>
using namespace std;

//void change(int *p1,int *p2)  //ָ�������ββ��ܸı��ַ
void change(int* &p1,int* &p2)  //�βα��ָ�����͵����þͿ��Ըı�ָ���������
{
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}


int main()
{
    int a1,a2;
    cin>>a1>>a2;
    int *p1 = &a1;
    int *p2 = &a2;
    cout<<&a1<<' '<<&a2<<endl;
    cout<<p1<<' '<<p2<<endl;
    //change(&a1,&a2);
    change(p1,p2);
    cout<<&a1<<' '<<&a2<<endl;  //û��
    cout<<p1<<' '<<p2<<endl;    //������
    cout<<a1<<' '<<a2<<endl;

    return 0;
}
