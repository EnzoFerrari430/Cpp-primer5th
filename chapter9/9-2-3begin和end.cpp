#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
    list<string> a = {"Milton","Shakespeare","Austen"};  //��ֵ��ʼ��
    auto it1 = a.begin();  //list<string>::iterator
    auto it2 = a.rbegin(); //list<string>::reverse_iterator
    auto it3 = a.cbegin(); //list<string>::const_iterator
    auto it4 = a.crbegin();//list<string>::const_reverse_iterator

    auto it7 = a.begin();  //����a��constʱ,it7��const_iterator
    auto it8 = a.cbegin(); //it8��const_iterator

    return 0;
}
