#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1 = "a string", *p = &s1;
    auto n = s1.size();
    auto m = p->size();
    cout<<m<<endl;





    return 0;
}
