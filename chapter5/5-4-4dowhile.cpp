#include <iostream>
#include <string>
using namespace std;
int main()
{
    /*
        do while����﷨
        do
            statement
        while(condition);

        conditionʹ�õı���������ѭ����֮��

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
