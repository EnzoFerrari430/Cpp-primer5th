#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
using std::string;
int main()
{
    vector<int> s1{0,1,2,3,4,5};
    int n = s1.size();
    int ia[n];
    int i;
    auto beg = s1.begin();
    for(i = 0;i<n;i++)
    {
        ia[i] = *beg;
        beg++;
    }
    for(auto c:ia)
    {
        cout<<c<<" ";
    }
    return 0;
}
