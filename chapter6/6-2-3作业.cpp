#include <iostream>
#include <string>
#include <vector>
using namespace std;

//6.17 2���β����Ͳ�ͬ,Ҫ���ַ��������޸ľͲ�����const
bool iSUp(const string &s)
{
    string::const_iterator sb;  //const string ���͵ĵ���Ҫ��string::const_iterator
    for(sb = s.begin() ;sb != s.end() ;++sb)
    {
        if( *sb >= 'A' && *sb <= 'Z')
        {
            return true;
        }
    }
    return false;
}

string lower(string &s)
{
    string::iterator sb;
    for(sb = s.begin() ; sb != s.end(); ++sb)
    {
        if( *sb >= 'A' && *sb <= 'Z')
            *sb = *sb + 'a' - 'A';
    }
    return s;
}

int main()
{
    /*
        6.16
        ��������Ĳ�����һ����ͨ��string���ã����ܴ�������ֵ�ַ���,�Ѳ����ĳ�const string &s

        6.18
        ����������Ϊû�к����壬���������������
        bool compare(matrix &mx1,matrix &mx2);
        vector<int>::iterator change_val(int n,vector<int>::iterator iv);

        6.19
        a.���Ϸ� ����ֻ��һ���β�,������2��ʵ��
        b.�Ϸ�
        c.�Ϸ�
        d.�Ϸ�

        6.20
        ���ı��βε�ʱ��Ӧ��ʹ�ó�������
        ���ܻ��޸ı�������Ҫ�ı��ʵ��
    */

    string s("hello WoRld");
    cout<<iSUp(s)<<endl;
    cout<<lower(s)<<endl;
    return 0;
}
