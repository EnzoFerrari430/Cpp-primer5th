#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���÷�����ֵ
char &get_val(string &str,string::size_type ix)
{
    return str[ix];    //get_val�ٶ�����ֵ����Ч��
}

//�б��ʼ������ֵ
vector<string> process()
{
    string expected("hello");
    string actual("world");
    if( expected.empty())
        return {};    //����һ����vector����
    else if( expected == actual )
        return {"functionx","okay"};  //�����б��ʼ����vector����
    else
        return {"functionx",expected,actual};
}

int main()
{
    /*
        ����һ��ֵ�ķ�ʽ�ͳ�ʼ��һ���������βεķ�ʽһ�������ص�ֵ���ڳ�ʼ�����õ��һ����ʱ��������ʱ�����Ǻ������õĽ��

        ��ﲻҪ���ؾֲ���������û�ָ�룺������ɺ�����ռ�õĴ洢�ռ�Ҳ��֮���ͷŵ���
        ��ˣ�������ֹ��ζ�žֲ����������ý�ָ������Ч���ڴ�����

        �����ķ������;������������Ƿ�����ֵ,����һ���������õĺ����õ���ֵ,�����������͵õ���ֵ
        �ر�ģ�������Ϊ���������Ƿǳ������õĺ����Ľ����ֵ


        C++11�±�׼�涨,�������Է��ػ����Ű�Χ��ֵ���б�.�������������ؽ�����˴����б�Ҳ������ʾ�����ķ��ص���ʱ�����г�ʼ��
    */
    string s("a value");
    cout<<s<<endl;
    get_val(s,0) = 'A';  //�õ�s[0] �������Ϊ'A'
    cout<<s<<endl;


    return 0;
}
