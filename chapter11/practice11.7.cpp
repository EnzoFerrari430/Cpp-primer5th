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
        while(cin>>children && children != "@q")  //退出标志，不能用ctrl + z 终止输入流
        {
            fams[lna].push_back(children);
        }
        cout<<"是否继续输入下一个家庭？1:是 ，0:否 ";
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
