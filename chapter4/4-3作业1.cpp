#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const char *cp = "helloworld";
    if( cp && *cp)
    {
        cout<<"1"<<endl;
    }

    int a;
    while( cin>>a && a!=42)
    {

    }


    return 0;
}
