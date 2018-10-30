#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
/*
关联容器的额外类型别名
    key_type        此容器类型的关键字类型
    mapped_type     每个关键字关联的类型：只适用于map
    value_type      对于set，与key_type相同
                    对于map，为pair<const key_type, mapped_type>
*/
int main()
{
    set<string>::value_type v1;         //v1是一个string
    set<string>::key_type v2;           //v2是一个string
    map<string,int>::value_type v3;     //v3是一个pair<const string,int>
    map<string,int>::key_type v4;       //v4是一个string
    map<string,int>::mapped_type v5;    //v5是一个int


    return 0;
}
