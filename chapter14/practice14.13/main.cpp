#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    Sales_data s1("C++",10,54);
    Sales_data s2("C++",11,66.6);
    Sales_data s3("java",10,11.5);
    Sales_data ss3("java",22,22.2);
    Sales_data s4;

    cin>>s4;
    cout<<s4<<endl;
    cout<<s1 + s2<<endl;
    cout<<s2 - s1<<endl;
    s3 += s4;
    cout<<s3<<endl;
    ss3 -= s4;
    cout<<ss3<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
