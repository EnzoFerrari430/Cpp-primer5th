#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    const string digital = "0123456789ABCDEF";  //所有的16进制数
    string res;
    string::size_type n;  //n是string::size_type类型，就是无符号类型
    while(cin>>n)
    {
        if(n<digital.size())
        {
            res += digital[n];
        }
    }
    cout<<res<<endl;




    //cout<<"hello world"<<endl;
    return 0;
}
