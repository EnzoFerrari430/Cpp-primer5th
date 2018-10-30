#include <iostream>
#include <string>
using namespace std;
/*
    ÿ����������������һ��string::size_typeֵ����ʾƥ�䷢����λ�ã����ƥ��ʧ�ܣ��򷵻�һ����Ϊstring::npos��static��Ա��
    ��׼�⽫npos����Ϊһ��const string::size_type���ͣ�����ʼ��Ϊ-1.

    string ������������һ��string::size_typeֵ����������unsigned���͡������int���������������ͱ�����Щ�������ز���һ��������

    ���е������������Ǵ�Сд���еġ�����ʱҪע���Сд
    find������ɼ򵥵������������Ҳ���ָ�����ַ��������ҵ����򷵻ص�һ��ƥ��λ�õ��±꣬���򷵻�npos��


string����������

    s.find(args)                    ����s��args��һ�γ��ֵ�λ��
    s.rfind(args)                   ����s��args���һ�γ��ֵ�λ��
    s.find_first_of(args)           ��s�в���args���κ�һ���ַ���һ�γ��ֵ�λ��
    s.find_last_of(args)            ��s�в���args���κ�һ���ַ����һ�γ��ֵ�λ��
    s.find_first_not_of(args)       ��s�в��ҵ�һ������args�е��ַ�
    s.find_last_not_of(args)        ��s�в������һ������args�е��ַ�

args���������µ���ʽ
    c,pos                   ��s��λ��pos��ʼ�����ַ�c��posĬ��Ϊ0
    s2,pos                  ��s��λ��pos��ʼ�����ַ���s2��posĬ��Ϊ0
    cp,pos                  ��s��λ��pos��ʼ����ָ��cpָ����Կ��ַ���β��c����ַ�����posĬ��Ϊ0
    cp,pos,n                ��s��λ��pos��ʼ����ָ��cpָ��������ǰn���ַ���pos��n��Ĭ��ֵ


*/
int main()
{
    /*
    string name("AnnaBelle");
    auto pos1 = name.find("Anna");  //pos1 == 0
    cout<<pos1<<endl;
    auto pos2 = name.find("annd");  //����unsigned��-1
    cout<<pos2<<endl;
    */

    /*
    //����������ַ������κ�һ���ַ�ƥ���λ�á�
    string numbers("0123456789"),name("r2d2");
    auto pos = name.find_first_of(numbers);  //numbers�Ǹ������ַ���
    cout<<pos<<endl;
    */

    /*
    //������һ�����ڲ����е��ַ�
    string numbers("0123456789");
    string dept("03714p3");
    auto pos = dept.find_first_not_of(numbers);  //������һ�����ڲ����е��ַ�
    cout<<pos<<endl;
    */


    //��������rfind��Ա�����������һ��ƥ�䣬
    string river("Mississippi");
    auto first_pos = river.find("is");
    auto last_pos = river.rfind("is");  //����s��args���һ�γ��ֵ�λ��
    cout<<first_pos<<" "<<last_pos<<endl;

    return 0;
}
