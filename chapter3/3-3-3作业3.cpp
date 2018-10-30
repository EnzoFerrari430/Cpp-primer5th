#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> s1;
    int num;
    int count;
    count = 0;
    int sum;
    sum = 0;
    while(cin>>num)
    {
        s1.push_back(num);
    }

    int n;
    n = s1.size();
    //cout<<n<<endl;
    int i;
    for(i = 0; i<s1.size(); i++)
    {
        sum += s1[i];
        count++;
        if(count == 2)
        {
            cout<<sum<<" ";
            count = 0;
            sum = 0;
        }
    }
    cout<<endl;
    for(i = 0;i<n - 1;i++)
    {
        sum = s1[i] + s1[i+1];
        cout<<sum<<" ";
    }
    cout<<endl;

    for(i = 0;i<n/2;i++)
    {
        sum = s1[i] + s1[n-i-1];
        cout<<sum<<" ";
    }
    return 0;
}
