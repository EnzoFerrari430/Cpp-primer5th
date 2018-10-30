#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
    list<string> a = {"Milton","Shakespeare","Austen"};  //赋值初始化
    auto it1 = a.begin();  //list<string>::iterator
    auto it2 = a.rbegin(); //list<string>::reverse_iterator
    auto it3 = a.cbegin(); //list<string>::const_iterator
    auto it4 = a.crbegin();//list<string>::const_reverse_iterator

    auto it7 = a.begin();  //仅当a是const时,it7是const_iterator
    auto it8 = a.cbegin(); //it8是const_iterator

    return 0;
}
