#include <iostream>
#include <string>
using namespace std;
/*
����string����������
n��len2��pos2�����޷���ֵ    unsigned

����1  string s(cp,n)          s��cpָ���������ǰn���ַ��Ŀ���������������Ӧ�ð���n���ַ�

����2  string s(s2,pos2)       s��string s2���±�pos2��ʼ���ַ��Ŀ�������pos2>s2.size(),���캯������Ϊδ����

����3  string s(s2,pos2,len2)  s��string s2���±�pos2��ʼlen2���ַ��Ŀ�������pos2>s2.size()�����캯������Ϊδ���塣
                        ����len2��ֵ�Ƕ��٣����캯�����࿽��s2.size()-pos2���ַ�

*/
int main()
{
    const char *cp = "hello world!!!";  //�Կ��ַ�����������
    char noNULL[] = {'H','i'};  //���Կ��ַ�����
    string s1(cp);  //����cp�е��ַ�ֱ���������ַ��� s1 == "hello world!!!"
    string s2(noNULL,2);  //����1
    string s3(noNULL);  //����ͨ����������ΪnoNULLû�п��ַ������Ի�ֹͣ��һ���п��ַ��ĵط�
    string s4(cp + 6,5);  //����1
    string s5(s1,6,5);  //����3
    string s6(s1,6);  //����2
    string s7(s1,6,20);  //����3
    //string s8(s1,16);  //�쳣 out_of_range



    return 0;
}
