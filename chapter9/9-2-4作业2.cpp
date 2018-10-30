#include <iostream>
#include <vector>
#include <list>
using namespace std;
//9.13
int main()
{

    list<int> li{1,2,3,4,5};
    vector<int> vi{5,4,3,2,1};
    vector<double> vd1(li.begin(),li.end());
    vector<double> vd2(vi.begin(),vi.end());
    for(auto c: vd1)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c: vd2)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
