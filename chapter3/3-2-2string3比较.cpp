#include <iostream>
using namespace std;

int main()
{
    /*
        ��ϵ�����< <= > >=�ֱ����һ��string�����Ƿ�С�ڣ�С�ڵ��ڣ�������һ��string����
        ��������㶼�ǰ��մ�Сд���е��ֵ�˳��

        ���ĳЩ��Ӧλ�ò�һ�£�string����ȽϵĽ������string�����е�һ�Բ�ͬ�ַ��ıȽϽ��

    */
    string s1 = "hello";
    string s2 = "helloworld";
    //s1<s2
    string s3 = "hdlloworld";
    //s3<s2
    string s4 = "hflloworld";
    //s4>s2
    string s5 = "job";
    //s5>s2
    if(s5<s2)
    {
        cout<<"s5<s2"<<endl;
    }
    else
    {
        cout<<"s5>=s2"<<endl;
    }



    return 0;
}
