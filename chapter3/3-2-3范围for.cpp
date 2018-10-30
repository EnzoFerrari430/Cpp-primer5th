#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
    C++11�±�׼
    ����for���������������������е�ÿ��Ԫ�ز����������е�ÿ��ִֵ��ĳ�ֲ���

    �﷨:
        for(declaration : expression)
            statement
    expression ��һ���������ڱ�ʾһ������
    declaration ������һ���������ñ��������ڷ��������еĻ���Ԫ��
    ÿһ�ε��� declaration�ı����ᱻ��ʼ��Ϊexpression���ֵ���һ��Ԫ��ֵ


*/
int main()
{
    string s1("some string");
    for(auto c : s1)
    {
        cout<<c<<endl;
    }

    string s2("hello world!!!!!");
    decltype(s2.size()) count = 0;
    for(auto d : s2)
    {
        if(ispunct(d))  //�ж��ַ��Ƿ��Ǳ�����
        {
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
