#include <iostream>
#include <list>
#include <deque>
using namespace std;
//9.20
int main()
{
    list<int> li{0,1,2,3,4,5,6,7,8,9};
    deque<int> even;
    deque<int> odd;

    for(list<int>::iterator it = li.begin();it != li.end() ;++it)
    {
        if( (*it) % 2 == 0)
            even.emplace_back(*it);
        else
            odd.emplace_back(*it);
    }

    for(auto c:even)
        cout<<c<<' ';
    cout<<endl;
    for(auto c:odd)
        cout<<c<<' ';
    cout<<endl;
    return 0;
}
