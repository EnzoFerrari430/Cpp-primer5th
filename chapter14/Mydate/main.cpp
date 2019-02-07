#include <iostream>
#include "Mydate.h"
using namespace std;

int main()
{
    Mydate d1("2018","11","20");
    Mydate d2("2018","11","20");
    Mydate d3;
    cout<<(d1 == d2)<<endl;
    cout<<(d1 != d2)<<endl;
    cout<<(d1 == d3)<<endl;
    cout<<(d1 != d3)<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
