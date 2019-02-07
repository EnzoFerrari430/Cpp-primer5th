#include <iostream>
#include <vector>
#include "String.h"
#include <algorithm>
using namespace std;

int main()
{
//    char text[] = "world";
//    String s(text);
//    cout<<s.c_str()<<endl<<endl;;
//
//    //���Ǻ����copy construct�Ĵ�ӡ����
//    vector<String> vS;
//    vS.push_back("hello1");
//    vS.push_back("hello2");
//    vS.push_back("hello3");
//    vS.push_back("hello4");
//    vS.push_back("hello5");
//    vS.push_back("hello6");
//    vS.push_back("hello7");

    String s1("one"),s2("two");
    cout<<s1 <<" "<<s2 <<endl<<endl;
    String s3(s2);
    cout<<s1<<" "<<s2 <<" "<<s3<<endl<<endl;
    s3 = String("three");
    cout<<s1<<" "<<s2 <<" "<<s3<<endl<<endl;
    vector<String> vs;
    //vs.reserve(4);
    vs.push_back(s1);
    vs.push_back(std::move(s2));
    vs.push_back(String("three"));
    vs.push_back("four");
    for_each(vs.begin(),vs.end(),[](const String &s){cout<<s<<" ";});
    cout<<endl;
    return 0;
}
