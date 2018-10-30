#include <iostream>
using namespace std;
int main()
{
    //5.1空语句  只有一个分号的语句  在语法上需要一条语句 但在逻辑上不需要，这就可以用空语句
    //5.2花括号括起来的语句和声明的序列，称为块.  当语法上需要一条语句 但是在逻辑上需要多条语句是的时候就可以用到块


    int sum = 0,val = 1;
    while(val<=10)
        sum += val,++val;
    cout<<sum<<endl;

    return 0;
}
