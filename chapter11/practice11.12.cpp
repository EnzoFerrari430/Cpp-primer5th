#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    pair<string,int> eq;
    vector<pair<string,int>> vec;
    int flag = 1;
    while(flag)
    {
        cout<<"����string��int: ";
        string str;
        int num;
        cin>>str>>num;
        eq.first = str;
        eq.second = num;
        //vec.push_back(make_pair(str,num));
        //vec.push_back({str,num});
        vec.push_back(eq);
        cout<<"�Ƿ�Ҫ��������: ";
        cin>>flag;
    }
    for(auto c : vec)
    {
        cout<<c.first<<" "<<c.second<<endl;
    }



    return 0;
}
