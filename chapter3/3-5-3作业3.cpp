#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstddef>
#include <iterator>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
int main()
{
    vector<int> s1{0,1,2,3,4,5,6};
    vector<int> s2{0,1,2,3,4,5,7};
    if(s1 == s2)
    {
        cout<<"2��vector�������"<<endl;
    }
    else
    {
        cout<<"2��vector���鲻��"<<endl;
    }



    return 0;
}
