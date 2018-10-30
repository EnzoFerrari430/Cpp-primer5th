#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> p)
{
    cout<<"inside the process function: "<<p.use_count()<<"\n";
}

int main()
{
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));
    cout<<p.use_count()<<endl;
    auto q = p;
    cout<<p.use_count()<<endl;
    cout<<"the int p now points to is: "<<*p<<endl;


    return 0;
}
