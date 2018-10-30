#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;

void error_msg(initializer_list<string> il)
{
    for(auto beg = il.begin() ;beg != il.end();++beg)
    {
        cout<<*beg<<' ';
    }
    cout<<endl;
}

int main()
{
    /*
        �������ʵ������δ֪������ȫ��ʵ�����Ͷ���ͬ�����ǿ���ʹ��initializer_list���͵��βΡ�
        ����һ�ֱ�׼�����ͣ����ڱ�ʾ�ض����͵�ֵ�����飬��ͬ��ͷ�ļ���

        ��vector��һ�����ǣ�initializer_list�����е�Ԫ����Զ���ǳ���.���ܱ��ı�
    */
    string expected = "ok to go";
    string actual = "ok to go1";
    string s;
    cin>>s;
    s.push_back('a');
    if(expected != actual)
        error_msg({"functionx",expected,actual,s});
    else
        error_msg({"functionx","OK"});


    return 0;
}
