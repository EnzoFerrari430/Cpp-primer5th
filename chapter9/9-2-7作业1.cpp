#include <iostream>
#include <vector>
using namespace std;
//9.15
int main()
{
    vector<int> vi1{1,2,3,4,5,6,7,8,9};
    vector<int> vi2{1,2,3,4,5,6,7,8,9,1};
    if(vi1 == vi2)
    {
        cout<<"they are equal"<<endl;
    }
    else if(vi1 > vi2)
    {
        cout<<"vi1 is bigger than vi2"<<endl;
    }
    else
    {
        cout<<"vi1 is smaller than vi2"<<endl;
    }


    return 0;
}
