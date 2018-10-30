#include <iostream>

int main()
{
    int i,&ri = i;
    i=5;
    ri=10;
    std::cout<<i<<" "<<ri<<std::endl;  //Êä³ö10 10

    return 0;
}
