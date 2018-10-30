#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1;
    string temp;
    while(getline(cin,temp))
    {
        s1 += + " " + temp;

    }
    cout<<s1<<endl;



    return 0;
}
