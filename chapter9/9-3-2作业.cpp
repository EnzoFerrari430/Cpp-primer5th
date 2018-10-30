#include <iostream>
#include <vector>
#include <string>
using namespace std;
//9.23   val val2 val3 val4都会指向同一个元素

//9.24
int main()
{
    vector<int> vi;
    cout<<vi[0]<<endl;
    cout<<vi.at(0)<<endl;
    cout<<vi.front()<<endl;
    cout<<*(vi.begin())<<endl;

    return 0;
}
