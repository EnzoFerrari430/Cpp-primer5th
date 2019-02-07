#include <iostream>
#include "String.h"
#include <vector>
using namespace std;

int main()
{
    char text[] = "world";
    String s(text);
    cout<<s.c_str()<<endl<<endl;;

    //不是很理解copy construct的打印次数
    vector<String> vS;
    vS.push_back("hello1");
    vS.push_back("hello2");
    vS.push_back("hello3");
    vS.push_back("hello4");
    vS.push_back("hello5");
    vS.push_back("hello6");
    vS.push_back("hello7");

    return 0;
}
