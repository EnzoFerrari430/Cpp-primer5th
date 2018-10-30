#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    map<string,vector<int> > ms;
    ms.insert({"ipadd",{127,0,0,1}});
    //插入类型 map<string,vector<int> >的value_type pair<const string,vector<int> >
    //返回类型 pair<map<string,vector>::iterator ,bool>


    return 0;
}
