#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    const string s = "Keep out!";
    for(auto &c : s)
    {
        //���ܸ�c��ֵ��c��ֵ�����޸����ַ���s
        //c = 'x';
        //cout<<s<<endl;
    }
    string s1;
    cin>>s1;
    string::size_type i;
    for(i = 0; i<s1.size(); i++)
    {
        if(!ispunct(s1[i]))
        {
            //ֱ�ӰѲ��Ǳ�������ͺ���!!!! ��ôû�뵽�أ�ǿ����ԭ�����ַ�����ɾ������
            cout<<s1[i];
        }
    }





    return 0;
}
