#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    char* s1 = "hello ";
    char* s2 = "world";
    //strcat����
    //��src��ָ�ַ�����ӵ�dest��β��(����dest��β����'\0')�����'\0'
    char *cp = new char[strlen("hello " "world") + 1]();  //���Ժ���Ҫ��() ��Ĭ�ϳ�ʼ��
    strcat(cp,s1);
    strcat(cp,s2);
    cout<<cp<<endl;


    string s3,s4;
    s3 = "hello ";
    s4 = "world";
    cout<<s3 + s4<<endl;


    delete[] cp;
    return 0;
}
