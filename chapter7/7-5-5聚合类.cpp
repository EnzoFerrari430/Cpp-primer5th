#include <iostream>
#include <string>
using namespace std;
/*
    �ۺ���ʹ���û�����ֱ�ӷ������Ա�����Ҿ�������ĳ�ʼ���﷨��ʽ����һ����������������������˵���Ǿۺ��ࣺ
        1.���г�Ա����public��
        2.û�ж����κι��캯��
        3.û�����ڳ�ʼֵ
        4.û�л��࣬Ҳû��virtual����
*/
//һ���ۺ���
struct Data
{
    int ival;
    string s;
    string book;
    int p;
};
int main()
{
    //���ʼ��˳�������������˳��һ��
    //�����ʼֵ�б��е�Ԫ�ظ���������ĳ�Ա�������򿿺�ĳ�Ա��ֵ��ʼ�������ʼֵ�б��Ԫ�ظ������Բ��ܳ�����ĳ�Ա����
    Data vall = {0,"Anna"};
    cout<<vall.p;
    return 0;
}
