#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
    һ��lambda���ʽ��ʾһ���ɵ��õĴ��뵥Ԫ,�����Ϊһ��δ��������������
    һ��lambda����һ���������ͣ�һ�������б��һ��������,lambda��������ں����ڲ�

    һ��lambda���ʽ����������ʽ
    [captrue list](parameter list) -> return type { function body }  ����ͨ������ͬ�� lambda����ʹ��β�÷�������

    lambda������Ĭ�ϲ���������ʵ����Ŀ��Զ���β���Ŀ���

    һ��lambdaͨ�����ֲ������������䲶���б�����ָ������ʹ����Щ����
    �����б�ָ��lambda�����ڲ��������ʱ����������Ϣ

*/
int main()
{
    //���Ժ��Բ����б�ͷ������ͣ���������Զ���������б�ͺ�����
    auto f = []{return 42;};  //������һ���ɵ��ö���f
    cout<<f()<<endl;  //ʹ�õ�������� ��ӡ42

    //��дһ���� "10-3-1���㷨���ݲ���" isShort���������ͬ���ܵ�lambda
    //[](const string &a,const string &b){return a.size() < b.size();}

    return 0;
}
