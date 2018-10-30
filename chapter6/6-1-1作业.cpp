#include <iostream>
using namespace std;
int Add(int n)
{
    int i = 1;
    static int num = 0;
    for(int v = 0; v< n; ++v)
    {
        num += i;
    }
    ++i;
    return num;
}
int main()
{
    cout<<Add(10)<<endl;
    cout<<Add(10)<<endl;
    cout<<Add(10)<<endl;
    cout<<Add(10)<<endl;
    return 0;
}
