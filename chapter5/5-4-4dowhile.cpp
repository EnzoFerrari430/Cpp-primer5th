#include <iostream>
#include <string>
using namespace std;
int main()
{
    /*
        do while语句语法
        do
            statement
        while(condition);

        condition使用的变量必须在循环体之外

    */
    string rsp;
    do
    {
        cout<<"plz enter two num: ";
        int val1 = 0,val2 = 0;
        cin>>val1>>val2;
        cout<<"the sum is: "<<val1 + val2<<"\n\n"<<"more? enter yes or no: ";
        cin>>rsp;
    }
    while( !rsp.empty() && rsp[0] != 'n');
    return 0;
}
