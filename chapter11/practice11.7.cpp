#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    string lna,children;
    vector<string> fnas;
    map<string,vector<string>> fams;
    int flag = 1;
    while(flag)
    {
        cin>>lna;
        while(cin>>children && children != "@q")  //�˳���־��������ctrl + z ��ֹ������
        {
            fams[lna].push_back(children);
        }
        cout<<"�Ƿ����������һ����ͥ��1:�� ��0:�� ";
        cin>>flag;
    }
    for( auto &c : fams)
    {
        cout<<c.first<<": ";
        for(auto &na : c.second)
        {
            cout<<na<<" ";
        }
        cout<<endl;
    }

    return 0;
}
