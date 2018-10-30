#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n,data;
    cin>>n>>data;  //当n输入有误时，cin进入错误状态，后续的IO操作都会失败
    cin.clear()；
    cin>>n>>data;
    cout<<n<<endl;
    cout<<data<<endl;

    return 0;
}
