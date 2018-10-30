#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
//9.14
int main()
{
    list<char *> lpc{"hello","world"};
    vector<string> vs;

    vs.assign(lpc.begin(),lpc.end());
    for(auto c: vs)
    {
        cout<<c<<' ';
    }

    return 0;
}
