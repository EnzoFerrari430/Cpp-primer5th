#include <iostream>
using namespace std;
int main()
{
    int i,j,k;
    i = 1;
    j = 2;
    k = 3;
    //算数>关系>逻辑
    //i != j<k  等价于 i!= (j<k)
    if( i!= j<k)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }





    return 0;
}
