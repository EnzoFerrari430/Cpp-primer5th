#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> si;
    int data;
    int num = 3;
    while(cin>>data)
    {
        si.push_back(data);
    }
    int cnt = count(si.begin(),si.end(),num);
    cout<<cnt<<endl;


    return 0;
}
