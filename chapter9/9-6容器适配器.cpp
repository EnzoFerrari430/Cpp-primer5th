#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
using namespace std;
/*
    ��׼�ⶨ��������˳�������������� stack queue priority_queue

    �����ϣ�һ����������һ�ֻ��ƣ���ʹĳ���������Ϊ������������һ������һ��

    һ����������������һ�����е��������ͣ�ʹ����Ϊ��������һ�ֲ�ͬ�����͡�

    �����������ǶԵײ�������һ�ַ�װ

    ÿ����������������2�����캯���� Ĭ�Ϲ��캯������һ���ն��󣬽���һ�������Ĺ��캯����������������ʼ��������

    Ĭ������£�stack��queue�ǻ���dequeʵ�ֵģ�priority_queue����vector֮��ʵ�ֵ�

    ������������Ҫ������������Ӻ�ɾ������������ˣ����������ܹ�����array֮��
*/
int main()
{
    //�ٶ�deq��һ��deque<int>�����ǿ�����deq����ʼ���µ�stack
    //stack<int> stk(deq);

    //���ǿ����ڴ���һ��������ʱ��һ��������˳��������Ϊ�ڶ���������������Ĭ����������
    //��vector��ʵ�ֵĿ�ջ
    stack<string,vector<string> > str_stk;
    //str_stk2��vector��ʵ�֣���ʼ��ʱ����svec�Ŀ���
    stack<string,vector<string> > str_stk2(svec);



    return 0;
}
