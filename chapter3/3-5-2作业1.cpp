#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
constexpr size_t n = 10;
int main()
{
    int i;
    int arry[n] = {};
    int s[n];
    for(i = 0;i<n;i++)
    {
        arry[i] = i;
        s[i] = arry[i];
    }
    for(auto c:arry)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:s)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    vector<int> s1;  //不要把它初始化
    for(i = 0;i<n;i++)
    {
        s1.push_back(i);
    }
    for(auto c:s1)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
