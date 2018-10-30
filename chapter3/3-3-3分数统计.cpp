#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> score(11,0);  //11个分数段，初始都是0
    unsigned grade;  //grade >=0
    while(cin>>grade)
    {
        if(grade<=100)
        {
            score[grade/10]++;
        }

    }
    for(auto c:score)
    {
        cout<<c<<" ";
    }






    return 0;
}
