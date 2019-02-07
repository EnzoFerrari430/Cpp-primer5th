#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class countLength
{
public:
    countLength(size_t n):sz(n){}
    //若lambda被声明为可变的，应该指的就是有类成员,则调用运算符就不再是const的了
    bool operator()(const string &s){
        return s.size() == sz;
    }
private:
    size_t sz;


};

int main()
{
    string file("words.txt");
    fstream in(file);
    int a[10] = {0};
    vector<string> vs;
    while(in.eof() == 0)  //为真跳出循环
    {
        string str;
        in>>str;
        vs.push_back(str);
    }

    for(int i = 1; i <= 10 ;++i)
    {
        cout<<"length is: "<<i<<"'s words are "<<count_if(vs.begin(),vs.end(),countLength(i))<<endl;
    }

    return 0;
}
