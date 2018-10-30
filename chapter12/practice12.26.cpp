#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
int main()
{
    allocator<string> alloc;
    string *const p = alloc.allocate(10);
    string *q = p;
    string s;
    while(cin>>s && q != p + 10)
    {
        alloc.construct(q++,s);
    }

    while(q != p)
    {
        cout<<*--q<<" ";
        alloc.destroy(q);
    }

    alloc.deallocate(p,10);


    return 0;
}
