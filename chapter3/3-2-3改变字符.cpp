#include <iostream>
#include <string>
#include <cctype>
#include <typeinfo>
using namespace std;

int main()
{
    string s1("helloworld");
    //����Ҫʹ�����ã������ʹ�����õĻ�,��ô����c����,��������s1�ַ�����ĳ���ַ���һ������.
    //����ʹ��toupper,�ı������������Ĵ�Сд,����ԭ�ȵ��ַ�����û���κεĸı�.
    //c = toupper(c) ʵ���ϸı���c�󶨵��ַ���ֵ
    for(auto &c :s1)
    {
        c = toupper(c);
    }
    cout<<s1<<endl;

    //s2Ϊ�գ�s2[0]�Ľ������δ�����
    string s2;
    cout<<s2[0]<<endl;

    string s3("machine gun");
    decltype(s3.size()) index;
    for(index = 0;index != s3.size() && !isspace(s3[index]);index++)
    {
        s3[index] = toupper(s3[index]);
    }
    cout<<s3<<endl;
    cout<<typeid(index).name()<<endl;
    string s4("machine gungungun");
    //decltype(s3.size()) index;
    for(int index = 0;index != s4.size() && !isspace(s4[index]);index++)
    {
        s4[index] = toupper(s4[index]);
    }
    cout<<s4<<endl;

    return 0;
}
