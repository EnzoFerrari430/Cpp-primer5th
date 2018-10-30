#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<double> vec{1,2,3,4,5,6,7,8,9.34,4,4,13,21};
    double sum = accumulate(vec.begin(),vec.end(),0);
    cout<<sum<<endl;



    return 0;
}
