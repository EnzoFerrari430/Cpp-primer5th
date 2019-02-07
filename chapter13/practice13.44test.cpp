#include "practice13.44String.h"
#include <vector>
#include <iostream>

void foo(String x)
{
    std::cout<<x.c_str()<<std::endl;
}

int main()
{
    char text[] = "world";
    String s(text);
    std::cout<<s.c_str()<<std::endl;


    return 0;
}
