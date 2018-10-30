#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
    ���˽��ܵ�������insert��erase�汾�⣬string���ṩ�˽����±�汾��
    �±�ָ���˿�ʼɾ����λ�ã�����insert������λ��֮ǰ��λ��
    s.insert(s.size(),5,'!');  ��sĩβ����5����̾��
    s.erase(s.size() - 5,5);   ��sɾ�����5���ַ�


string &insert(int p0, const char *s);������p0λ�ò����ַ���s

string &insert(int p0, const char *s, int n);������p0λ�ò����ַ���s��ǰn���ַ�

string &insert(int p0,const string &s);������p0λ�ò����ַ���s

string &insert(int p0,const string &s, int pos, int n);������p0λ��ǰ�����ַ���s��pos��ʼ������n���ַ�

string &insert(int p0, int n, char c);//��p0������n���ַ�c
iterator insert(iterator it, char c);//��it�������ַ�c�����ز�����������λ��

void insert(iterator it, const_iterator first, const_iterator last);//��it�������first��ʼ��last-1�������ַ�

void insert(iterator it, int n, char c);//��it������n���ַ�c
*/
int main()
{
//��׼��string���ͻ��ṩ�˽���C����ַ������insert��assign�汾
    string s;
    const char *cp = "Stately,plump Buck";
    s.assign(cp,7);  //s == "Stately"
    s.insert(s.size(),cp + 7);
    cout<<s<<endl;

//����Ҳ����ָ������������string�����ַ������ַ����뵽��ǰstring�л��赱ǰstring
    string ss = "some string",ss2 = "some other string";
    ss.insert(0,ss2);  //0λ��֮ǰ����s2�Ŀ���
    cout<<ss<<endl;
    ss.insert(0,ss2,0,ss2.size());  //��p0λ��ǰ�����ַ���s��pos��ʼ������n���ַ�
    cout<<ss<<endl;



    return 0;
}
