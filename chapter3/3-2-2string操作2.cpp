#include <iostream>
using namespace std;

int main()
{
    //����ȡ�ո�
    /*
    string word;
    while(cin>>word)
    {
        cout<<word<<endl;
    }
    */

    //��ȡ�ո�
    string line;
    //ÿ�ζ�ȡһ���У�ֱ��ĩβ
    /*
    while(getline(cin,line))
    {
        if(!line.empty())
        {
            //�����ж� ֱ�ӻس�ֻ���һ��
            cout<<line<<endl;
        }

    }
    */

    //string.size()�����ַ����ĸ���
    //size�������ص���һ���޷��ŵ������������һ�����ʽ�Ѿ���size�����˾Ͳ�Ҫʹ��int��
    while(getline(cin,line))
    {
        if(line.size()>10)
        {
            cout<<line<<endl;
        }
    }



    return 0;
}
