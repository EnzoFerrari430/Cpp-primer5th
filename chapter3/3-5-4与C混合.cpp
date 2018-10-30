#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;
int main()
{
    //����string�����C����ַ���
    string s("Hello World");  //s��������Hello World
    /*
        1.����ʹ���Կ��ַ����������ַ���������ʼ��string�����Ϊstring����ֵ
        2.��string����ļӷ�����������ʹ���Կ��ַ����������ַ�������Ϊ����һ��������󣨲���2�����ǣ���Ϊ��Ҫһ��string���󣩣�
            ��string����ĸ��ϸ�ֵ����������ʹ���Կ��ַ��������ַ�������Ϊ�Ҳ���������

        ���Ƿ������Ͳ������ˣ�������string����ֱ�ӳ�ʼ��ָ���ַ���ָ��.Ϊ����ɸù��ܣ�stringר���ṩ��һ����Ϊc_str�ĳ�Ա����
    */

    //char *str = s;  ����ֱ�ӽ�string����ת����char*��
    const char *str = s.c_str();  //������ı��ַ����������
    //cout<<str<<endl;


    /*
        ������ʹ��һ������Ϊ��һ���������͵����鸳��ֵ��
        Ҳ������ʹ��vector�����ʼ�����飬�෴������ʹ����������ʼ��vector����
        Ϊ��ʵ�����Ŀ�ģ�ֻҪָ�������������Ԫ�ص�ַ��β���ַ�Ϳ�����

    */
    int int_arr[] = {0,1,2,3,4,5};
    //ivec��6��Ԫ�أ��ֱ���int_arr�ж�ӦԪ�صĸ���
    vector<int> ivec(begin(int_arr),end(int_arr));
    vector<int> sub_ivec(int_arr+1,int_arr+4);
    for(auto c:ivec)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:sub_ivec)
    {
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}
