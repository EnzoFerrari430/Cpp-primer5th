#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    string lna,children;
    multimap<string,string> fams;
    int flag = 1;
    while(flag)
    {
        cin>>lna;
        cin>>children;
        fams.insert({lna,children});
        cout<<"�Ƿ�Ҫ�������룿1��������0���˳�: ";
        cin>>flag;
    }

    for( auto &c : fams)
    {
        cout<<c.second<<" "<<c.first<<endl;
    }


    return 0;
}
