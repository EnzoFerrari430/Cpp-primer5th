#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    map<int,string> li;
    li[25] = "Enzo";
    li[1] = "Alan";
    map<int,string>::iterator it = li.begin();
    it->second = "pan";
    cout<<it->first<<" "<<it->second<<endl;



    return 0;
}
