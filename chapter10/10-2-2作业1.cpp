#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec{3,3,0,3,0,4,1,9,9,4,1,1,1,1,9,0,1,4};
    fill_n(vec.begin(),vec.size(),0);
    for(auto c:vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
