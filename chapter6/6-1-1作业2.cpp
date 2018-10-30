#include <iostream>
using namespace std;
int proc()
{
    static int data = -1;
    return ++data;
}
int main()
{
    cout<<proc()<<endl;
    cout<<proc()<<endl;
    cout<<proc()<<endl;
    cout<<proc()<<endl;
    cout<<proc()<<endl;
    cout<<proc()<<endl;
    cout<<proc()<<endl;
    return 0;
}
