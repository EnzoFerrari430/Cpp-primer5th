#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto ib = vi.begin();
    while(ib != vi.end())
    {
        cout<< *ib++<<endl;
        //cout<< *ib++<<endl;  µÈ¼ÛÓÚ*ib; ++ib;
    }





    return 0;
}
