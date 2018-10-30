#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

//9.28
void insert_str(forward_list<string> &flstr,string s1,string s2)  //记得传入一个引用
{
    auto bhead = flstr.before_begin();
    auto head = flstr.begin();
    auto lst = flstr.end();
    while(head != lst)
    {
        if( *head == s1)
        {
            flstr.insert_after(head,s2);
            break;
        }
        else
        {
            ++bhead;
            ++head;
        }
    }
    if(head == lst)
    {
        flstr.insert_after(bhead,s2);
    }
}

int main()
{
    forward_list<string> ffstring{"hello","world","this","me"};
    insert_str(ffstring,"this","is");
    for(auto c:ffstring)
        cout<<c<<' ';
    cout<<endl;

    return 0;
}
