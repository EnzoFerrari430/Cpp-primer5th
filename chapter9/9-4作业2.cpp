#include <iostream>
#include <vector>
using namespace std;
void fun(int n)
{
    vector<int> vi;
    vi.reserve(1024);
    int data = 10;
    for(int i = 0;i<n;++i)
    {
        vi.emplace_back(data);
    }
    cout<<"����"<<n<<"������֮��������size: "<<vi.size()<<endl;
    cout<<"����"<<n<<"������֮��������capacity: "<<vi.capacity()<<endl;
}
int main()
{
    fun(256);
    fun(512);
    fun(1000);
    fun(1048);

    return 0;
}
