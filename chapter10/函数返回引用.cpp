#include <iostream>
using namespace std;


//����ϵͳ��û�����̽����ر������ڴ�����������������������ʱ�ġ����ȶ��ġ�
int &add()
{
    int a,b;
    a = 4;
    b = 5;
    int c = a + b;
    int &d = c;
    return d;


}

int main()
{
    cout<<add()<<endl;

    return 0;
}
