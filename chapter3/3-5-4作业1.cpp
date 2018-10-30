#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    const char ca[] = {'h','e','l','l','o'};
    const char *cp = ca;
    while(*cp)
    {
        cout<<*cp<<endl;
        ++cp;
    }
    //输出不只是hello 会一直读下去直到遇到'\0'




    return 0;
}
