#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //vector<int> ivec;  //ivec����int���͵Ķ���
    //vector<Sales_item> Sales_vec;  //����Sales_item���͵Ķ���
    vector<vector<string>> file;  //��������Ԫ����vector����

    /*
        ͨ������£�����ֻ�ṩvector��������Ԫ�ص������������ø���ʼֵ����ʱ��ᴴ��һ��ֵ��ʼ����Ԫ�س�ֵ�����������������е�����Ԫ�ء�
        �����ֵ��vector�����е�Ԫ�����;���
    */
    vector<int> ivec(10);  //10��Ԫ�أ�ÿ����ʼֵ����0
    vector<string> svec(10);  //10��Ԫ�أ�ÿ�����ǿյ�string����
    //vector<int> vi = 10; //Ҫ��ֱ�ӳ�ʼ������ʽָ�������Ĵ�С

    //Բ���źͻ����ŵ�����
    vector<int> v1(10);    //10��Ԫ�أ�ֵ����0
    vector<int> v2{10};    //һ��Ԫ�أ�ֵ��10
    vector<int> v3(10,1);  //10��Ԫ�أ�ֵ����1
    vector<int> v4{10,1};  //2��Ԫ�أ�ֵ��10��1


    vector<string> v5{"hi"};      //�б��ʼ��:v5ֻ��һ��Ԫ��
    //vector<string> v6("hi");    //wrong ����ʹ���ַ�������ֵ����vector����
    vector<string> v7{10};        //��10��Ĭ�ϳ�ʼ����Ԫ��
    vector<string> v8{10,"hi"};   //��10��ֵΪ"hi"��Ԫ��
    //vector<string> v9{"hi",10}; //˳�򲻶�
    //ֻ��v5���б��ʼ��



    return 0;
}
