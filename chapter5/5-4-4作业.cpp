#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1,str2;
    do
    {
        cin>>str1>>str2;
        if(str1.size() < str2.size())
        {
            cout<<str1<<endl;
        }
        else if(str1.size() > str2.size() )
        {
            cout<<str2<<endl;
        }
        else
        {
            cout<<str1<<endl<<str2<<endl;
        }
    }
    while(cin);  //while(cin)  =====> while(!cin.fail())
    //cin��һ�������󣬶�>>�����������ߵ�������Ҳ����˵cin>>val����cin��
    //����while(cin)��ͬ��while(cin>>val)��Ҳ�������Ƿ��ȡ�ɹ�


    return 0;
}
