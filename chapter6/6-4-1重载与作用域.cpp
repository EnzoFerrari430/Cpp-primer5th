#include <iostream>
using namespace std;
/*
    ���ض��������һ�����ʲ�û�з���ʲô�ı䡣����������ڲ����������������֣��������������������������ͬ��ʵ�塣
    �ڲ�ͬ�����������޷����غ�����

    ��C++�����У����ֲ��ҷ��������ͼ��֮ǰ
*/
string read();
void print(const string &);
void print(double);  //����print����

void foolBar(int ival)
{
    bool read = false;  //��������:����������read
    string s = read();  //����:read��һ������ֵ�����Ǻ���

    //���õ�ϰ�ߣ�ͨ����˵���ھֲ���������������������һ���õ�ѡ��
    void print(int);    //�µ�������������֮ǰ��print

    print("value: ");   //����:print(const string &)�����ص���
    print(ival);        //��ȷ:��ǰprint(int)�ɼ�
    print(3.14);        //��ȷ�����õ���print(int), print(double)�����ص���
}

int main()
{


    return 0;
}
