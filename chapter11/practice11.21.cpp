#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    string word;
    map<string,size_t> word_count;
    //²åÈëµü´úÆ÷·µ»Ø pair<map<string,size_t>::iterator,bool>
    while(cin>>word)
    {
        ++word_count.insert({word,0}).first->second;
    }

    for(auto c: word_count)
    {
        cout<<c.first<<" occurs "<<c.second<<" times"<<endl;
    }



    return 0;
}
