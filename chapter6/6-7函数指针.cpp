#include <iostream>
#include <string>
using namespace std;
/*
    ����ָ��ָ����Ǻ������Ƕ���
    �ﺯ�������������ķ������ͺ��β����͹�ͬ�������뺯�����޹�

    bool lengthCompare(const string &,const string &);

    �ú�����������bool(const string &,const string &)
    ��Ҫ����һ������ָ��ú�����ָ�룬ֻ��Ҫ��ָ���滻����������
    bool (*pf)(const string &,const string &);  ����Ҫ����

    ָ��ͬ�������͵�ָ��䲻��ת�������ǿ��Ը�ֵnullptr��0��ʾ��
*/
bool lengthCompare(const string &,const string &);


bool lengthCompare(const string &s1,const string &s2)
{
    return true;
}

bool (*pf)(const string &s1,const string &s2);
int main()
{
    pf = lengthCompare;  //pfָ����ΪlengthCompare�ĺ���
    pf = &lengthCompare; //�ȼ۵ĸ�ֵ���  ȡ��ַ���ǿ�ѡ��

    //����ֱ��ʹ��ָ����ָ����øú�����������ǰ����
    bool b1 = pf("hello","goodbye");              //����lengthCompare����
    bool b2 = (*pf)("hello","goodbye");           //һ���ȼ۵ĵ���
    bool b3 = lengthCompare("hello","goodbye");   //��һ���ȼ۵ĵ���

    pf = 0;

    return 0;
}
