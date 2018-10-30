#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <typeinfo>
using namespace std;
int main()
{
    map<int,string> m = {{1,"123"},{2,"sz"}};
    using KeyType = map<int,string>::key_type;

    cout<< typeid(KeyType).name()<<endl;
    cout<< typeid(decltype(m[1])).name()<<endl;


    map<int,int> v = {{1,111},{2,222}};
    cout<< typeid(decltype(v[1])).name()<<endl;

    string str;
    cout<< typeid(str).name()<<endl;
    return 0;
}
