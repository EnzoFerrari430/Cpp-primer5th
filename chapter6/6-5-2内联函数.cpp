#inlcude <iostream>
#include <string>
using namespace std;
/*
    ���ú���һ�����ȼ۱��ʽҪ��һЩ��
    �����������Ա��⺯�����õĿ���

    ������ָ��Ϊ��������(inline)��ͨ�����ǽ�����ÿ�����õ���"������"չ��
    �������������Ż���ģ��С������ֱ�ӣ�Ƶ�����õĺ������ܶ����������֧�������ݹ麯��������һ�����еĺ���Ҳ��������ڵ��õ�������չ��

*/

inline const string &shorterString(const string &s1,const string &s2)
{
    return s1.size() <= s2.size()? s1: s2;
}

int main()
{

    //���������º���
    cout<<shorterString(s1,s2)<<endl;
    //�ڱ��������չ���������������ʽ
    cout<<(s1.size() <= s2.size()? s1: s2 )<<endl;
    //�Ӷ�������shorterString��������ʱ�Ŀ���

    return 0;
}
