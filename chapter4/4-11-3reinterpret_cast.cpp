#include <iostream>
#include <string>
using namespace std;
//reinterpret_castͨ��Ϊ��������λģʽ�ṩ�ϵͲ���ϵ����½���
int main()
{
    int i = 84;  //ascii��84ֵ��T
    char *c = reinterpret_cast<char *>(&i);
    int *ip = &i;
    char *pc = reinterpret_cast<char *>(ip);
    //pc��ָ����ʵ������һ��int�����ַ��������pc������ͨ���ַ�ָ��ʹ�ÿ��ܾͻᷢ������
    string str(pc);
    cout<<&i<<endl;
    cout<<ip<<endl;
    cout<<pc<<endl;    //T
    cout<<*pc<<endl;   //T
    cout<<c<<endl;     //T
    cout<<*c<<endl;    //T


    return 0;
}
