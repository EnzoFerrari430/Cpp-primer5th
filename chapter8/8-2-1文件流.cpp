#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string ifile{"E:\\Enzo.txt"};
    //�����ļ�����������ṩ��һ���ļ�������open���Զ�������
    ifstream in(ifile);  //����һ��ifstream���򿪸����ļ�


    /*
    ofstream out(ifile);
    for(int i = 0;i<10;++i)
    {
     string str;
     cin>>str;
     out<<str<<"\n";//������ļ�
    }
    */

    /*
    while(in.eof() == 0)  //Ϊ������ѭ��
    {
        string str;
        in>>str;
        cout<<str<<endl;
    }
    */
    //in ��ȡ���
    in.close();  //�ر��ļ�

    //��Ҫ��ʹ�û����Ͷ���ĵط������ǿ����ü̳����͵Ķ���������

    return 0;
}
