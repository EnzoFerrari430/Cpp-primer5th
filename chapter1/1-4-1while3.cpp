#include <iostream>

int main()
{
    int v1,v2;
    std::cout<<"请用户输入2个整数"<<std::endl;

    std::cin>>v1>>v2;
    if(v1<v2)
    {
        while(v1<=v2)
        {
            std::cout<<v1<<" ";
            v1++;
        }
    }
    else if(v1>v2)
    {
        while(v2<=v1)
        {
            std::cout<<v2<<" ";
            v2++;
        }
    }
    else
    {
        std::cout<<v1<<" ";
    }



    return 0;
}
