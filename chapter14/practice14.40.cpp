#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class ShorterString
{
public:
    bool operator()(const string &s1,const string &s2)const{
        return s1.size() < s2.size();
    }
};

class BiggerEqual
{
public:
    BiggerEqual(size_t n):sz(n){}
    bool operator()(const string &s){
        return s.size() >= sz;
    }
private:
    size_t sz;
};

class print
{
public:
    void operator()(const string &s){ cout<<s<<endl; }
private:

};

void elimdups(vector<string> &words)
{
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

string make_plural(size_t ctr,const string &word,const string &ending)
{
    return ctr>1?word+ending:word;
}


void biggies(vector<string> &words,vector<string>::size_type sz)
{
    elimdups(words);
    //stable_sort(words.begin(),words.end(),[sz](const string &a,const string &b){return a.size() < b.size();})
    stable_sort(words.begin(),words.end(),ShorterString());
    auto wc = find_if(words.begin(),words.end(),BiggerEqual(sz));
    auto count = words.end() - wc;
    cout<<count <<" " <<make_plural(count,"word","s") <<" of length "<< sz << " or longer"<<endl;
    for_each(wc,words.end(),print());
    cout<<endl;
}

int main()
{
    vector<string> vec{ "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle" };
    biggies(vec,4);
    return 0;
}
