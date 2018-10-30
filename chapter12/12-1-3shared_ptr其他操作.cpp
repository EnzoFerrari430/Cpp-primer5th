#include <iostream>
#include <memory>
using namespace std;
int main()
{
    shared_ptr<int> p(new int(42));
    p.reset(new int(2323));
    cout<<*p<<endl;
    cout<<p.use_count()<<endl;



    return 0;
}
