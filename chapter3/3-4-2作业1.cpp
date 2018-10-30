#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> s1;
    int num;
    while(cin>>num)
    {
        s1.push_back(num);
    }
    for(auto c = s1.begin(); (c+1) != s1.end();c++)
    {
        cout<<*c + *(c+1)<<" ";
    }
    cout<<endl;
    for(auto it1 = s1.begin(),it2 = s1.end()-1;it1< it2;it1++,it2--)
    {
        cout<<*it1 + *it2<<" ";
    }






    return 0;
}
