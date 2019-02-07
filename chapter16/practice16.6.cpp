#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T,unsigned size>
T* begin_def(T (&arr)[size])
{
    return arr;
}

template <typename T,unsigned size>
T* end_def(T (&arr)[size])
{
    return arr + size;
}

int main()
{
    string s[] = {"aaaaa","bbbbb","ccccc","dddddd"};
    cout<<*(begin_def(s)+ 2 )<<endl;
    cout<<*(end_def(s) - 2)<<endl;

    return 0;
}
