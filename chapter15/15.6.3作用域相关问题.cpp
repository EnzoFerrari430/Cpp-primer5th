#include <iostream>
using namespace std;

int a = 0;
int main()
{
    int a = 1;
    {
        int a = 2;
        cout<<a<<endl;
    }

    cout<<a<<endl;



}
