/*
    char ch = getVal();
    int ival = 42;
    switch(ch)
    {
        case 3.14:  //���� case��ǩ����һ������

        case ival:  //���� case��ǩ����һ������
    }

*/

#include <iostream>
using namespace std;
int main()
{
    char ch;
    unsigned int acnt = 0,ecnt = 0,icnt = 0,ocnt = 0,ucnt = 0;
    while(cin>>ch)
    {
        //switch������ȶ�������ı��ʽ��ֵ,���ʽ��ֵת������������,Ȼ����ÿ��case��ǩ��ֵ�Ƚ�
        //�����ĳ��case��ǩ��ֵƥ��ɹ�������Ӹñ�ǩ��ĵ�һ����俪ʼִ�У�ֱ��������switch�Ľ�β��������һ��break���
        switch(ch)
        {
        case 'a':
            ++acnt;
            break;
        case 'e':
            ++ecnt;
            break;
        case 'i':
            ++icnt;
            break;
        case 'o':
            ++ocnt;
            break;
        case 'u':
            ++ucnt;
            break;
        }
    }
    cout<<"num a: "<<acnt<<endl;
    cout<<"num e: "<<ecnt<<endl;
    cout<<"num i: "<<icnt<<endl;
    cout<<"num o: "<<ocnt<<endl;
    cout<<"num u: "<<ucnt<<endl;



    return 0;
}
