#include <iostream>
#include <string>
using namespace std;
/*
string�ඨ����2������ĳ�Ա������append��replace����2���������Ըı�string���ݡ�append�Ĳ�������stringĩβ���в��������һ�ּ�д��ʽ

�޸�string�Ĳ���
s.replace(range,args)       ɾ��range�ڵ��ַ����滻Ϊargsָ�����ַ���range������һ���±��һ�����ȣ�������һ��ָ��s�ĵ�������
                            ����һ��ָ��s������
s.erase(pos,len)            ɾ����λ��pos��ʼ��len���ַ������len��ʡ����ɾ����pos��ʼֱ��ĩβ�������ַ�,����һ��ָ��s������

s.insert(pos,args)          ��posλ��֮ǰ����argsָ�����ַ���pos�������±����������±�汾����һ��s���ã�
                            �������汾���ز����һ���ַ��ĵ�����


*/
int main()
{
    string s("C++ Primer"),s2 = s;
    s.insert(s.size()," 4th Ed");
    s2.append(" 4th Ed");  //�ȼ۷����� ��" 4th Ed"׷�ӵ�s2
    cout<<s<<endl;
    cout<<s2<<endl;
    //replace�����ǵ���erase��insert��һ�ּ�д��ʽ
    //��" 4th Ed"�滻��" 5th Ed"
    //cout<<s[11]<<endl;
    s.erase(11,3);  //��11λ��ʼ ɾ��3λԪ��  ��ʼλ����0
    s.insert(11,"5th");
    //��λ��11��ʼ��ɾ��3���ַ�������"5th"
    s2.replace(11,3,"5th");
    cout<<s<<endl;
    cout<<s2<<endl;
    string ss("hello world!!!!!!");
    auto c = ss.begin();
    //ss.insert(c+5,{'1','2','3'});
    auto d = ss.insert(c+5,'a');
    cout<<ss<<endl;
    cout<<*d<<endl;
    return 0;
}
