#include <iostream>
using namespace std;
int main()
{
    int ival;
    while(cin>>ival)
    {
        auto old_state = cin.rdstate();  //cin�ĵ�ǰ״̬
        cout<<old_state<<endl;
        cout<<"ival: "<<ival<<endl;
    }
    auto old_state = cin.rdstate();
    cout<<old_state<<endl;


    return 0;
}
