#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <memory>
using namespace std;
/*

    �������ȵĻ���������ַ��ᱻ�ض�
*/
int main()
{
    int size{0};
    //cout<<size<<endl;
    cin>>size;
    char *p = new char[size+1];  //��Ϊ������һ��'\0'
    cin.ignore();  //������һ���ַ�
    cout<<"input the string: ";
    cin.get(p,size+1);
    cout<<p<<endl;


    delete[] p;

    //12.25
    int *pa = new int[10];
    delete[] pa;
    return 0;
}
