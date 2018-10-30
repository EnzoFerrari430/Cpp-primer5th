#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    int num1,num2;
    cin>>num1>>num2;
    try
    {
        if( 0 == num2 )
            throw runtime_error("除数不能为0");
        cout<<static_cast<double>(num1)/num2<<endl;
    }
    catch(runtime_error err)
    {
        cout<<err.what()<<endl;
    }



    return 0;
}
