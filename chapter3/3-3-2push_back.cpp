#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
        vector����ֱ�ӳ�ʼ��������3�����
        1.��ʼֵ��֪����������
        2.��ʼֵ����һ��vector����ĸ���
        3.����Ԫ�صĳ�ʼֵ����һ����
    ���Ǹ��������Ǵ���vector���󣬲�֪��ʵ��Ԫ�صĸ���

    vector�ĳ�Ա����push_back���������Ԫ��
    push_back�����һ��ֵ����vector�����βԪ��ѹ��vector�����β��
    */


    //warning ���ѭ�����ڲ�����vector�������Ԫ�ص���䣬����ʹ�÷�Χforѭ��
    vector<int> v2;  //�յ�vector����
    for(int i = 0;i<100;i++)
    {
        v2.push_back(i);  //����������ѹ����β
    }

    //��ʱ��Ҫʵʱ��ȡ���ݸ���vector����
    string word;
    vector<string> text;
    while(cin>>word)
    {
        text.push_back(word);
    }






    return 0;
}
