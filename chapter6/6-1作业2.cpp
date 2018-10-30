#include <iostream>
using namespace std;
int Mypower(int n)
{
    int res = 1;
    while(n>0)
    {
        res *= n;
        --n;
    }
    return res;
}
int ABS(int n)
{
    return (n>0?n:-n);
}
int main()
{
    int num;
    cin>>num;
    cout<<Mypower(num)<<endl;

    int i = -3;
    cout<<ABS(i)<<endl;

    return 0;
}
