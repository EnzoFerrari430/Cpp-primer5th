#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int i;
    while(cin>>i)
    {
        v.push_back(i);
    }
    vector<int>::iterator beg;
    beg = v.begin();
    while(beg != v.end() && *beg >= 0)
    {
        ++beg;
    }
    if(beg == v.end())
    {
        cout<<"¶¼´óÓÚ0"<<endl;
    }


    return 0;
}
