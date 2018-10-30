#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    map<string,size_t> word_count;
    string word;
    while(cin>>word)
    {
        ++word_count[word];
    }

    //´òÓ¡½á¹û
    for(const auto &w:word_count)
    {
        cout<<w.first<<": occurs: "<<w.second<<( w.second > 1? " times" : " time" )<<endl;
    }
    return 0;
}
