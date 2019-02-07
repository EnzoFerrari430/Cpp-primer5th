#include <iostream>
#include <string>
using namespace std;

template <typename T,unsigned size>
constexpr unsigned getSize(T (&arr)[size])
{
    return size;
}

int main()
{
    string s[] = {"hell","asd"};
    cout<<getSize(s)<<endl;
    char c[] = "sdfskjg";
    cout<<getSize(c)<<endl;
    return 0;
}
