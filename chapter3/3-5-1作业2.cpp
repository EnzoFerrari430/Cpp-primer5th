#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int ia[10];  //�ں���������Զ�����ʼ��Ϊ0
string sa[10];  //�ں������ⱻ��ʼ��Ϊ��
int main()
{
    string sa2[10];  //����ʼ��Ϊ��
    int ia2[10];  //�ں������ڳ�ʼ����ȷ��
    for(auto c:sa)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:ia)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:sa2)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:ia2)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
