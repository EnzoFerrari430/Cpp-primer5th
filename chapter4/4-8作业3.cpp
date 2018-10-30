#include <iostream>
using namespace std;
int main()
{
    unsigned long ul1 = 3;
    unsigned long ul2 = 7;

    //加括号 <<优先级高
    cout<< (ul1 & ul2)<<endl;
    cout<<(ul1 | ul2)<<endl;
    cout<<(ul1 && ul2)<<endl;
    cout<<(ul1 || ul2)<<endl;




    return 0;
}
