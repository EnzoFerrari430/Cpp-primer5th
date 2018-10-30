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
    cout<<"输入"<<n<<"个数字之后容器的size: "<<vi.size()<<endl;
    cout<<"输入"<<n<<"个数字之后容器的capacity: "<<vi.capacity()<<endl;
}
int main()
{
    fun(256);
    fun(512);
    fun(1000);
    fun(1048);

    return 0;
}
