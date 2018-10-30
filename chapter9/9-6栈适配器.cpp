#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
�����ջ����
    s.pop()                 //ɾ��ջ��Ԫ�أ��������ظ�Ԫ�ص�ֵ
    s.push(item)            //����һ����Ԫ��ѹ��ջ������Ԫ��ͨ���������ƶ�item����,������args����
    s.emplace(args)
    s.top();                //����ջ��Ԫ�أ���������Ԫ�ص���ջ

ÿ�����������������ڵײ��������͵Ĳ����������Լ����������������ֻ����ʹ��������������������ʹ�õײ��������͵Ĳ���
e.g.    initStack.push(ix);
�������ͼ��initStack�ĵײ�deque�����ϵ���push_back����Ȼstack�ǻ���dequeʵ�ֵģ��������ǲ���ֱ��ʹ��deque�Ĳ�����������һ��
stack�ϵ���push_back��������ʹ��stack�Լ��Ĳ���-push

*/
int main()
{
    stack<int> initStack;  //��ջ
    for(size_t ix = 0; ix != 10; ++ix)
    {
        initStack.push(ix);  //initStack����0-9
    }
    while( !initStack.empty() )
    {
        int value = initStack.top();
        cout<<value<<' ';
        initStack.pop();  //����ջ��Ԫ��,����ѭ��
    }



    return 0;
}
