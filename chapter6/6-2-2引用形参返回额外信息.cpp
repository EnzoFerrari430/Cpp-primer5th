#include <iostream>
#include <string>
using namespace std;
string::size_type find_char(const string &s,char c,string::size_type &occurs)
{
    auto ret = s.size();  //��һ�γ��ֵ�λ��
    occurs = 0;
    for( decltype(ret) i = 0;i<s.size();++i )
    {
        if( s[i] == c)
        {
            if(ret == s.size() )
                ret = i;
            ++occurs;
        }
    }
    return ret;  //���ִ���ͨ��occurs��ʽ����
}
int main()
{
    /*
        ���庯����ʹ�䷵�ض����Ϣ
            1.����һ���µ���������(�Ҳ¿���������C�Ľṹ��)�������������������Ϣ��
            2.����������һ�����������ʵ�Σ����䱣���ַ����ֵĴ���

    */
    string s;
    string::size_type ctr;  //������¼���ֵĴ���
    getline(cin,s);
    auto index = find_char(s,'o',ctr);
    cout<<index<<' '<<ctr<<endl;


    return 0;
}
