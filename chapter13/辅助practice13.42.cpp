#include "StrVec.h"

using namespace std;
int main()
{
    StrVec s;
    s.push_back("hello");


    for(auto it = s.begin(); it != s.end(); ++it )
    {
        cout<<*it<<" ";
    }
    cout<<endl;



    return 0;
}
