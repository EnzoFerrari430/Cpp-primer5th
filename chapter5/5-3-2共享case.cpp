#include <iostream>
using namespace std;
int main()
{
    char ch;
    unsigned num = 0,othernum = 0;
    while(cin>>ch)
    {
        switch(ch)
        {
        //һ�㲻Ҫʡ��case��֧�����break;��䡣���ûдbreak��ü�һ��ע�ͣ�˵��������߼�
        //default��ǩ�����û���κ�һ��case��ǩ��ƥ����switch���ʽ��ֵ������ִ�н�����default��ǩ��������.
        //���磬��������һ������ֵ��ͳ�Ʒ�Ԫ����ĸ��������ֻҪ��default��֧�ڲ��ϵ���othernum�ı����Ϳ�����
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++num;
            break;
        default:
            ++othernum;
            break;
        }
    }
    cout<<num<<endl;
    cout<<othernum<<endl;
    return 0;
}
