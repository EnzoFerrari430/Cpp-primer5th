#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;
int main()
{
    vector<string>::value_type AnInt;
    cout<<typeid(AnInt).name()<<endl;
    string str;
    cout<<typeid(str).name()<<endl;


    return 0;
}
