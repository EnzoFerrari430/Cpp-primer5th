#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec{10,9,8,7,6,5,4,3,2,1};
    for(auto it = vec.end()-1 ; it != vec.begin() - 1 ; --it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
    return 0;
}
