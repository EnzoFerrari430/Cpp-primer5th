#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    String s1("hello world");
    String s2("hello world");
    String s3("hello java");
    cout<<(s1 == s2)<<endl;
    cout<<(s1 == s3)<<endl;
    cout<<(s1 < s3)<<endl;
    cout<<(s1 >= s3)<<endl;


    //practice14.26
    const String s4 = s1;
    cout<<s1<<endl;
    cout<<s4<<endl;
    cout<<s1[2]<<endl;
    cout<<s4[2]<<endl;
    s1[2] = 'a';
    //s4[2] = 'b';  �����±���������ص��ǳ���
    cout<<s1[2]<<endl;
    cout<<s4[2]<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
