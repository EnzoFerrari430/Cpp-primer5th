#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    list<int> ilst;

    //copy使用插入迭代器
    copy(vec.rbegin()+3,vec.rend()-2,back_inserter(ilst));
    for(auto c: ilst)
        cout<<c<<' ';
    cout<<endl;


    return 0;
}
