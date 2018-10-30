#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{

    int num = 5;
    auto f = [&num]()mutable->bool{return --num? true : false;};
    while( f() )
    {
        cout<<num<<endl;
    }
    cout<<num<<endl;
    return 0;
}
