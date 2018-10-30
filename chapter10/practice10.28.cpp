#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
int main()
{
    std::vector<int> v1{1,2,3,4,5,6,7,8,9};
    std::list<int> v2,v3,v4;
    copy(v1.cbegin(),v1.cend(),inserter(v2,v2.begin()));
    copy(v1.cbegin(),v1.cend(),back_inserter(v3));
    copy(v1.cbegin(),v1.cend(),front_inserter(v4));
    std::cout<<"v2 use inserter: ";
    for(auto c: v2)
        std::cout<<c<<' ';
    std::cout<<std::endl;

    std::cout<<"v3 use back_inserter: ";
    for(auto c: v3)
        std::cout<<c<<' ';
    std::cout<<std::endl;

    std::cout<<"v4 use front_inserter: ";
    for(auto c: v4)
        std::cout<<c<<' ';
    std::cout<<std::endl;




    return 0;
}
