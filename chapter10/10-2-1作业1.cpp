#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> vec{1991,1,49721,141321,44};
    int sum = accumulate(vec.begin(),vec.end(),0);
    cout<<sum<<endl;

    return 0;
}
