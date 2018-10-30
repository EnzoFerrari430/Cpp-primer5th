#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <list>
using namespace std;
int main()
{
    vector<int> vi{0,1,1,2,3,3,4,5,5,6,7,7,8,9,9,10};
    list<int> li;
    unique_copy(vi.begin(),vi.end(),back_inserter(li));
    for(auto c: li)
        cout<<c<<' ';
    cout<<endl;



    return 0;
}
