#include <iostream>
using namespace std;
/*
    ���ͱ�����ĳ�����͵�ͬ���

*/
//��ͳ����
typedef double wages;  //wages��double��ͬ���
typedef wages base,*p;  //base��double��ͬ��ʣ�p��double*��ͬ���

//C++11 �·��� ��������
//using ������ʼ������� �����͵Ⱥ� �ѵȺ���ߵ����ֹ涨���ұ����͵ı���
//using SI = Sales_item;  //SI��Sales_item��ͬ���
using SI = int;  //SI��Sales_item��ͬ���

//ָ�룬���������ͱ���
/*
    ������ͱ���ָ�����Ǹ������ͻ��� �������������һ����Ч��
*/
//����pString��char*�ı���
typedef char *pString;
int main()
{
    wages hours;
    //pString str = new char;
    //cin>>str;
    //cout<<str<<endl;

    char c = 42;
    char d = 2;
    //���һ�� const int i; int�͵ĳ��� pStringָ��char��ָ��
    const pString cstr1 = &c;  //ָ��char�ĳ���ָ��  const�������ֱ����cstr1 �����ǳ��� pString�Ѿ�������ָ�� �����ǳ���ָ��
    const char *cstr2 = &c;  //����2�ֲ���һ���ģ���������  ָ��const char��ָ��
    //delete(str);
    return 0;
}
