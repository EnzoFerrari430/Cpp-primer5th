#include <iostream>
#include <vector>
using namespace std;
bool iSchildArray(vector<int> vi1,vector<int> vi2)
{
    vector<int>::iterator iv;
    for(iv = vi1.begin() ; iv != vi1.end(); ++iv)
    {
        if(*iv != vi2[iv - vi1.begin()])
            return false;
    }
    return true;
}
int main()
{
    vector<int> v1{0,1,2,3,4,5,6};
    vector<int> v2{0,1,2,3,3};
    int size1,size2;
    size1 = v1.size();
    size2 = v2.size();

    if(size1 > size2)
        cout<<(iSchildArray(v2,v1)?"true":"false")<<endl;
    else
        cout<<(iSchildArray(v1,v2)?"true":"false")<<endl;

    return 0;
}
