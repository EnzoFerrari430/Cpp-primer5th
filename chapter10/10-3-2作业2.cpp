#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//10.15
//int i = 42;
//auto add = [i](int num){ return i + num; };

void add(int lhs,vector<int> nums)
{
    for_each(nums.begin(),nums.end(),[lhs](int a){cout<<lhs + a<<' ';});
}

int main()
{

    int a,b;
    cin>>a>>b;
    vector<int> vec;
    vec.push_back(b);
    add(a,vec);



    return 0;
}
