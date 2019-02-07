#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T& item)
{
    typename T::size_type i = 0;
    for(;i < item.size(); ++i)
    {
        cout<< item[i] <<endl;
    }
}

template <typename T>
void print2(T& item)
{
    typename T::size_type i = 0;
    for(typename T::iterator it = item.begin() ;it != item.end(); ++it)
    {
        cout<< *it <<endl;
    }
}


int main()
{
    vector<int> vi = {1,2,3,4,5,6};
    print(vi);
    cout<<endl;
    print2(vi);

    return 0;
}
