#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    map<string,size_t> word_count;
    string word;
    while(cin>>word)
    {
        auto ret = word_count.insert({word,1});
        if( !ret.second )
        {
            ++((ret.first)->second);  //ret.first µÃµ½pair<string,size_t>
        }
    }
    map<string,size_t>::iterator it,ie = word_count.end();
    for(it = word_count.begin(); it != ie; ++it)
    {
        cout<<it->first<<" occurs "<<it->second<<" times"<<endl;
    }

    return 0;
}
