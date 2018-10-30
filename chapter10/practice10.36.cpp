#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>  //distance
using namespace std;
int main()
{
    list<int> ilst{1,2,0,6,4,0,3,6,8,7,9,5,4,1,9,8,8,0,14,6,5,8,4,1};
    auto pos = find(ilst.rbegin(),ilst.rend(),0);
    cout<<distance(pos,ilst.rend());


    return 0;
}
