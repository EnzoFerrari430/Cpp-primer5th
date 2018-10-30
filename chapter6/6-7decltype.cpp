#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

string::size_type sumLength(const string &,const string &)
{
    cout<<"sunLength"<<endl;
}
string::size_type largerLength(const string &,const string &)
{
    cout<<"largerLength"<<endl;
}

decltype(sumLength) *getFcn(const string &)
{
    cout<<typeid(largerLength).name()<<endl;
}

int main()
{

    getFcn("hello");
    return 0;
}
