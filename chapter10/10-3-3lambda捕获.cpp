#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
    �봫ֵ�������ƣ�����ֵ�����ǰ���Ǳ������Կ������������ͬ���ǣ�������ı�����ֵ����lambda����ʱ�����������ǵ���ʱ����
*/

void fcn1()
{
    size_t v1 = 42;  //�ֲ�����
    //��v1��������Ϊf�Ŀɵ��ö�����
    auto f = [v1]{return v1;};
    v1 = 0;
    auto j = f();  //j = 42�� f���������Ǵ�����ʱv1�Ŀ���
    cout<<"f() "<<f()<<endl;
    cout<<"v1 "<<v1<<endl;
    cout<<"j "<<j<<endl;
}

//�����Բ������õķ�ʽ�������
//һ�������÷�ʽ����ı����������κ����͵�������Ϊ���ơ���������lambda��������ʹ�ô˱���ʱ��ʵ����ʹ�õ����������󶨵Ķ���
//���ò���ͷ�������������ͬ�����ơ�������ǲ������÷�ʽ����һ���������ͱ���ȷ�������õĶ�����lambdaִ�е�ʱ���Ǵ��ڵ�
//��������lambda�ı�������򵥻�
void fcn2()
{
    size_t v1 = 42;  //�ֲ�����
    //����f2������v1������
    auto f2 = [&v1]{return v1;};
    v1 = 0;
    auto j = f2();  //j = 0; f2������v1�����ã����ǿ���
    cout<<"f2() "<<f2()<<endl;
    cout<<"v1 "<<v1<<endl;
    cout<<"j "<<j<<endl;


}


/*
��ʽ����
    ������ʾ�г�Ҫʹ�õı���֮�⣬�������ñ���������lambda���еĴ������ƶ�����Ҫʹ����Щ������ &���߱������������õĲ���ʽ
    =��ʾ����ֵ����ķ�ʽ

    //szΪ��ʽ����ֵ����ʽ
    wc = find_if(words.begin(),words.end(),[=](const string &s){return s.size() >= sz;});
*/

//���ֱ���ֵ���� ʣ�����ò���
void biggiest(vector<string> &words,vector<string>::size_type sz,ostream &os = cout,char c = ' ')
{
    //os��ʽ����,���ò���ʽ     c��ʽ����ֵ����ʽ
    for_each(words.begin(),words.end(),[&,c](const string &s){os<<s<<c;});
    //os��ʽ����,���ò���ʽ     c��ʽ����ֵ����ʽ
    for_each(words.begin(),words.end(),[=,&os]{const string &s}{os<<s<<c;});
    //��ʹ�û��ʹ����ʽ����ʽ����ʽʱ�������б�ĵ�һ��Ԫ�ر�����һ��&��=���˷���ָ����Ĭ�ϲ���ʽΪ���û�ֵ
    //��
}

int main()
{
    fcn1();
    fcn2();
    return 0;
}
