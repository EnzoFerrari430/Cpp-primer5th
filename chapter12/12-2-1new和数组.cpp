#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

/*
    Ϊ����new����һ���������飬����Ҫ��������֮���һ�Է����ţ�����ָ��Ҫ����Ķ������Ŀ
    �������еĴ�С���������ͣ��������ǳ���

    ��̬���鲢������������
    new����һ������ʱ���õ��Ĳ������������͵Ķ��󣬶��ǵõ�һ������Ԫ�����͵�ָ��
    ��˲��ܶԶ�̬�������begin��end��Χforѭ��
*/

int main()
{
    //int *pia = new int[10];  //piaָ���һ��int
    //Ҳ�������ͱ����ķ���
    typedef int arrT[42];  //arrT��ʾ42��int����������
    int *p = new arrT;  //����һ��42��int�����飬pָ���һ��int

    cout<<typeid(arrT).name()<<endl;


    /*
    @��ʼ����̬���������

    */

    //Ĭ������£�new����Ķ�����Ĭ�ϳ�ʼ����
    //���Զ������е�Ԫ�ؽ���ֵ��ʼ�����������ڴ�С֮���һ�Կ�����
    int *pia = new int[10];  //10��δ��ʼ����int
    int *pia2 = new int[10]();  //10����ʼ��Ϊ0��int
    string *psa = new string[10];  //10����string
    string *psa2 = new string[10]();  //10����string

    //C++11�±�׼�����ṩԪ�س�ʼ�����Ļ������б�
    //10��int�ֱ����б��ж�Ӧ�ĳ�ʼ������ʼ��
    int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};
    //10��string��ǰ4���ø����ĳ�ʼ������ʼ����ʣ��Ľ���ֵ��ʼ��
    string *psa3 = new string[10]{"a","an","the",string(3,'x')};

    int i;
    for(i = 0;i<10;++i)
    {
        cout<<*(pia3+i)<<" ";
    }
    cout<<endl;


    //��̬����һ���������ǺϷ���
    char arr[0];  //cp5��˵�� ���󣬲��ܶ��峤��Ϊ0�����飬  �������ﲻ������warning
    char *cp = new char[0];  //cp5��˵����ȷ������cp���ܽ����ã�  ����������Խ�����
    //cout<<*cp<<endl;\


    //Ϊ���ͷŶ�̬���飬����ʹ��һ��������ʽ��delete--��ָ��ǰ����Ͽշ����Ŷ�
    delete []pia;  //����piaָ���������Ԫ�أ����ͷŶ�Ӧ���ڴ档�����е�Ԫ�ذ���������



    return 0;
}
