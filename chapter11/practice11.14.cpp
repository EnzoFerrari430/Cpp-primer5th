#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
int main()
{
    string lna,children;
    int date;
    vector<string> fnas;
    map<string,vector<pair<string,int>>> fams;
    int flag = 1;
    while(flag)
    {
        cin>>lna;
        while(cin>>children && children != "@q")  //�˳���־��������ctrl + z ��ֹ������
        {
            cin>>date;
            fams[lna].push_back(make_pair(children,date));
        }
        cout<<"�Ƿ����������һ����ͥ��1:�� ��0:�� ";
        cin>>flag;
    }
    for( auto &c : fams)
    {
        cout<<c.first<<":"<<endl;
        for(auto &na : c.second)
        {
            cout<<na.first<<" "<<na.second<<endl;
        }
        cout<<endl;
    }

    return 0;
}
