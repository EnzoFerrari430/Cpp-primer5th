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
        while(cin>>children && children != "@q")  //退出标志，不能用ctrl + z 终止输入流
        {
            cin>>date;
            fams[lna].push_back(make_pair(children,date));
        }
        cout<<"是否继续输入下一个家庭？1:是 ，0:否 ";
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
