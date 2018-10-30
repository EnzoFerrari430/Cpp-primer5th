#include <iostream>
using namespace std;
int main()
{
    //m%(-n) 等价于m%n (-m)%n 等价于-(m%n)
    cout<<21 % 6<<endl;
    cout<<21 % -6<<endl;
    cout<<-21 % -6<<endl;




    return 0;
}
