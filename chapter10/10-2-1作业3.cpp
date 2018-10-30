#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<char *> vec1{"111","222","333"};
    vector<char *> vec2{"111","222","333"};

    cout<<equal(vec1.begin(),vec1.end(),vec2.begin());  //»á³ö¾¯¸æ


    return 0;
}
