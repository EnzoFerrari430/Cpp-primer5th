#include <iostream>
using namespace std;
int main()
{
    /*
        (+)2��string������Ӿ��ǰ�������������Ҳ�������󴮽�����
        (+=)���ϸ�ֵ������ǰ��Ҳ�string��������׷�ӵ����string����ĺ���
    */
    string s1 = "hello ";
    string s2 = "world";
    string s3 = s1 + s2;
    //�ȼ���s1 += s2;
    cout<<s3<<endl;

    //��׼��������ַ�����ֵ���ַ�������ֵת����string����
    //string������ַ�����ֵ�Լ��ַ�������ֵ����һ�������ʱ�����뱣֤ "+"�ŵ�����������һ��string����
    string s4 = "hello";
    string s5 = "world";
    string s6 = s4 + " " +s5;
    cout<<s6<<endl;

    //string s7 = "hello " + "world"; +������û��string����
    string s8 = s4 + ", " + "world";  //��ȷ����Ϊs4 + ", " �����ܷ���һ��string����

    //string s9 = "hello" + ", " + s5; //����  ��Ϊ"hello" + ", " ������ֵ����ֱ�����


    return 0;
}
