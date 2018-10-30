#include <iostream>
#include <cstdlib>
using namespace std;

int factorial(int val)
{
    if(val>1)
        return val * factorial(val - 1);
    return 1;
}

int main()
{
    /*
    if(0)
        return EXIT_FAILURE;
    else
        return EXIT_SUCCESS;
    */

    cout<<factorial(5)<<endl;

    return 0;
}
