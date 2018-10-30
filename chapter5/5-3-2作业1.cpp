#include <iostream>
using namespace std;
int main()
{
    char ch;
    int cnt = 0;
    while(cin>>ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ++cnt;
    }
    cout<<cnt<<endl;


    return 0;
}
