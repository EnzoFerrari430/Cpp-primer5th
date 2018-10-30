#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> sval;
    vector<string> str;
    vector<int> cnt;
    vector<string>::iterator ib;
    vector<string>::iterator is;
    vector<int>::iterator i;
    string s1;
    int maxnum = 0;
    while(cin>>s1)
    {
        sval.push_back(s1);
    }
    ib = sval.begin();
    while(ib != sval.end())
    {
        is = str.begin();
        while( is != str.end() )
        {
            if(*ib == *is)
            {
                ++cnt[is - str.begin()];
                break;
            }
            else
            {
                ++is;
            }
        }
        if( is == str.end())
        {
            str.push_back(*ib);
            cnt.push_back(1);
        }
        ++ib;
    }
    //最大值
    for(i = cnt.begin() ; i != cnt.end() ;++i)
    {
        if(*i > maxnum )
        {
            maxnum = *i;
        }
    }
    for(i = cnt.begin() ; i != cnt.end() ;++i)
    {
        if(maxnum == *i)
        {
            cout<<"最大值是: "<<maxnum<<" 对应单词是: "<<str[i-cnt.begin()]<<endl;
        }
    }
    return 0;
}
