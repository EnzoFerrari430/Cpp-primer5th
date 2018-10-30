#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::vector;
int main()
{
    int ia[] = {0,1,2,3,4,5};
    vector<int> s1(begin(ia),end(ia));
    for(auto c:s1)
    {
        cout<<c<<" ";
    }
    return 0;
}
