#include <iostream>
#include <string>
using namespace std;
/*
s.compare�ļ��ֲ�����ʽ
s2                      �Ƚ�s��s2

pos1,n1,s2              ��s�д�pos1��ʼ��n1���ַ���s2���бȽ�

pos1,n1,s2,pos2,n2      ��s�д�pos1��ʼ��n1���ַ���s2�д�pos2��ʼ��n2���ַ����бȽ�

cp                      �Ƚ�s��cpָ����Կ��ַ���β���ַ�����

pos1,n1,cp              ��s�д�pos1��ʼ��n1���ַ���cpָ����Կ��ַ���β���ַ�������бȽ�

pos1,n1,cp,n2           ��s�д�pos1��ʼ��n1���ַ���ָ��cpָ��ĵ�ַ��ʼ��n2���ַ����бȽ�

*/

int main()
{
    string str("helloworld");
    cout<<str.compare("hElloworld")<<endl;



    return 0;
}
