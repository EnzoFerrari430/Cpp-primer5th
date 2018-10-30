#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
int main()
{
    vector<int> s1(11,0);  //³É¼¨·Ö¶Î
    int grade;
    auto c = s1.begin();
    while(cin>>grade)
    {
        int n = grade/10;
        (*(c+n))++;
    }
    for(auto vi:s1)
    {
        cout<<vi<<" ";
    }





    return 0;
}
