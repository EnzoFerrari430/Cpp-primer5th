#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <typename T>
void print(T (&arr)[5])
{
    for(auto elem:arr)
    {
        cout<<elem<<endl;
    }
}



int main()
{
    int a[5] = {1,3,5,7,9};
    char str[5] = "Enzo";
    double d[5] = {1.1,3.3,5.5,7.7,9.9};
    vector<int> vi{2,4,6,7,8};
    string s("hello");

    print(a);
    print(str);
    print(d);
    //print(vi);
    //print(s);

    return 0;
}
