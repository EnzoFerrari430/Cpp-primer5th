#include <iostream>
#include <string>
using namespace std;
/*
    ʲô�ǿɵ��ö��󣺾����ڸö�������ܼӵ����������()
    C++�������м��ֿɵ��ö��󣺺���������ָ�롢lambda���ʽ��bind�����Ķ����Լ������˺����������������

    Ȼ����������ͬ���͵Ŀɵ��ö���ȴ���ܹ���ͬһ�ֵ�����ʽ��
    ������ʽָ���˵��� �����ص����͡� �Լ����ݸ� �����õ�ʵ�����͡� ��

    int(int ,int)  ����һ���������ͣ�����������int������һ��int

*/

//��ͬ���Ϳ��ܾ�����ͬ�ĵ�����ʽ
//��ͨ����
int add(int i,int j){return i+j;}
//lambda,�����һ��δ�����ĺ���������
auto mod = [](int i,int j){return i % j;};
//����������
struct divide
{
    int operator()(int denominator,int divisor){
        return denominator / divisor;
    }
};
int main()
{


    return 0;
}
