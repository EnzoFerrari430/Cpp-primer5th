#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    //11.9
    map<string,list<int>> pos;

    //11.10  vector是随机访问迭代器，符合严格弱序。list是双向迭代器，不符合严格弱序
    map<vector<int>::iterator,int> m1;
    map<list<int>::iterator,int> m2;

    return 0;
}
