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

    //11.10  vector��������ʵ������������ϸ�����list��˫����������������ϸ�����
    map<vector<int>::iterator,int> m1;
    map<list<int>::iterator,int> m2;

    return 0;
}
