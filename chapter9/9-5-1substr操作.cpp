#include <iostream>
#include <string>
using namespace std;
/*
    substr��������һ��string������ԭʼstring��һ���ֻ�ȫ���Ŀ��������Դ��ݸ�substrһ����ѡ��λ�úͼ���ֵ
    ���ַ�������
    s.substr(pos,n) ����һ��string������s�д�pos��ʼ��n���ַ��Ŀ�����pos��Ĭ��ֵ��0.n��Ĭ��ֵΪs.size() - pos����������pos��ʼ�������ַ�
*/
int main()
{
    string s("hello world");
    string s2 = s.substr(0,5);  //s2 == "hello"
    string s3 = s.substr(6);  //s3 == "world"
    string s4 = s.substr(6,11);  //s4 == "world"
    //string s5 = s.substr(12);  //out_of_range�쳣




    return 0;
}
