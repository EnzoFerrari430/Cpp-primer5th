#include <iostream>
#include <string>
using namespace std;

const string &shorterString(const string &s1,const string &s2)
{
    return s1.size() <= s2.size()? s1: s2;
}
//��������Ĳ����ͷ���ֵ����const string�����ã���������Ҫ�õ�һ����ͨ�����ã�ʹ��const_cast����������һ��
string &shorterString(string &s1,string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1),const_cast<const string &>(s2));
    return const_cast<string &>(r);
}
int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    //��Ϊ������const string�����ã����Բ����޸�
    shorterString(s1,s2)[0] = 'H';
    //���ڣ��Ƚ�ʵ��ת���ɶ�const�����ã�����const�汾��shortString����������һ��const string���ã��������ʵ���ϰ�����ĳ����ʼ��
    //�ǳ���ʵ���ϣ�������ǿ����ٽ���ת����һ����ͨ��string &
    //shorterString('a');  ƥ�䲻������,��������

    cout<<s1<<endl;


    //��ҵ6.39
    //a. ����ﵫ�Ǳ��벻���� ���const�Ƕ���const ��Ӱ�촫�뺯���Ķ��������ظ�����
    //b. ����ﲻ���������������˷��������⣬��������Ҫ�ض���ͬ
    //c. ��ȷ
    return 0;
}
