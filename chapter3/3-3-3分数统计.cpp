#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> score(11,0);  //11�������Σ���ʼ����0
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
