#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    const string digital = "0123456789ABCDEF";  //���е�16������
    string res;
    string::size_type n;  //n��string::size_type���ͣ������޷�������
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
