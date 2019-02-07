#include <iostream>
#include <string>
#include <list>
#include <string>
#include <vector>
using namespace std;

template <typename Iterator,typename Value>
Iterator MyFind(Iterator first,Iterator last,const Value& v2)
{
    for(;first != last ; ++first)
    {
        if( *first == v2 )
            return first;
    }
    return first;
}

int main()
{
    vector<int> vi{1,2,3,4,5};

    list<string> ls{"hello","world","C++","C"};
    auto it = MyFind(vi.begin(),vi.end(),3);
    cout<<*it<<endl;
    //it = MyFind(ls.begin(),ls.end(),"C++");  it已经被指定为int*
    auto it2 = MyFind(ls.begin(),ls.end(),"C++");
    cout<<*it2<<endl;



    return 0;
}
