#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
using namespace std;
int main()
{
    string sFile("E:\\CC++\\C++ primer\\chapter12\\12-27.txt");
    ifstream in(sFile);
    vector<string> input;  //按行保存文件中的内容
    map<string,set<decltype(input.size())>> dictionary;  //单词出现的行号
    decltype(input.size()) LineNo{0};

    for(string line; getline(in,line) ; ++LineNo)
    {
        input.push_back(line);
        istringstream line_stream(line);
        for(string text,word; line_stream>>text; word.clear() )
        {
            remove_copy_if(text.begin(),text.end(),back_inserter(word),::ispunct);
            dictionary[word].insert(LineNo);
        }
    }

    while(true)
    {
        cout<<"enter word to look for,or q to quit: ";
        string s;
        if( !(cin>>s) || "q" == s)
        {
            break;
        }
        auto found = dictionary.find(s);
        if(found != dictionary.end())
        {
            cout<<s<<" occurs "<<found->second.size() <<(found->second.size() > 1 ? " times " : "time")<<endl;
            for(auto i : found->second)
            {
                cout<<"\t(line "<< i + 1 << ")" <<input.at(i)<<endl;
            }
        }
        else
        {
            cout<<s<<" occurs 0 time"<<endl;
        }
    }


    return 0;
}
