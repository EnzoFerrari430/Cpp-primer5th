#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
    ÿ��������һ���������ļ�ģʽ������ָ�����ʹ���ļ�
        in          �Զ��ķ�ʽ��
        out         ��д�ķ�ʽ��
        app         ÿ��д����ǰ����λ���ļ�ĩβ
        ate         ���ļ���������λ���ļ�ĩβ
        trunc       �ض��ļ�
        binary      ��2���Ʒ�ʽ��



    ifstream�������ļ�Ĭ��inģʽ��
    ofstream�������ļ�Ĭ��outģʽ��
    fstream�������ļ�Ĭ��in��outģʽ��

    ��outģʽ�򿪵��ļ��ᶪʧ���е�����
*/
int main()
{
    //Ĭ������£������Ǵ�һ��ofstreamʱ���ļ������ݻᱻ��������ֹһ��ofstream��ո����ļ����ݵķ�����ͬʱָ��appģʽ
    //�����⼸����䣬file1���ᱻ�ض�
    ofstream out("file1");  //�����������ģʽ���ļ����ض��ļ�
    ofstream out2("file1",ofstream::out); //�����Ľض��ļ�
    ofstream out3("file1",ofstream::out | ofstream::trunc);
    //Ϊ�˱����ļ����ݣ����Ǳ�����ʽָ��appģʽ
    ofstream app("file1",ofstream::app);  //����Ϊ���ģʽ
    ofstream app2("file1",ofstream::out | ofstream::app);


    return 0;
}
