#include <iostream>
#include <string>
using namespace std;
int main()
{
    string numbers("0123456789"),name("r2d2");

    auto pos = numbers.find(name);  //·µ»ØunsignedµÄ-1
    cout<<pos<<endl;


    return 0;
}
