#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    //10.14 auto add = [](int lhs,int rhs){return lhs + rhs;};
    int a,b;
    cin>>a>>b;
    auto f = [a,b](){return a+b;};
    cout<<f()<<endl;
    return 0;
}
